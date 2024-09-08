begin P_read arriving

	open "dir/input.csv" for reading save result as V_pointer //Automod  v14  or greater 
	
	read V_useless(1),V_useless(2),V_useless(3) from V_pointer with delimiter ";"
	
	
	while V_stop_production<1  do 
		begin 
		
		read V_id, V_type, V_rugos from V_pointer with delimiter ";" at end 
		  
			begin 
				print " My input file is fully read" to message 
				send to die 
			end 	
		
		
		wait for normal 150,5 sec
		set V_start_time to ac
		clone 1 to P_init
		end 
end

///////////////////////////////////////////////////////////////////////
///////////////////////  SCRIPT INIZIALE MAIN /////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////  INIT PROCESS /////////////////////////

begin P_init arriving
	set this load type = L_prod_init
	if V_type= "Left" then set V_type_ID to 1
	if V_type= "Right" then set V_type_ID to 2
		
	move into Q_in
	move into conv.sta_in
	set V_Random to oneof(10:10, 90:0)
	send to nextof(P_polish(1), P_polish(2))
end

///////////////////////---------------/////////////////////////

///////////////////////  POLISHING PROCESS /////////////////////////

begin P_polish arriving
	travel to conv.sta_polishing_(procindex)
	
	move into Q_polishing(procindex)
	use R_polishing(procindex) for normal 5.5*(1+(V_rugos/100)),0.5 min
	
	move into conv.sta_polishing_(procindex)
	send to nextof(P_painting(1), P_painting(2))
end

///////////////////////---------------------/////////////////////////

///////////////////////  PAINTING PROCESS /////////////////////////
	
begin P_painting arriving
	travel to conv.sta_painting_(procindex)
	
	move into Q_painting(procindex)
	use R_painting(procindex) for 4 min
	move into conv.sta_painting_(procindex)

	send to P_drying
end

///////////////////////-------------------/////////////////////////

///////////////////////  DRYING PROCESS /////////////////////////

begin P_drying arriving
	travel to conv.sta_drying
	move into Q_drying
	use R_drying for 2 min
	move into conv.sta_drying
	
	send to P_clearcoat
end

///////////////////////-----------------/////////////////////////

///////////////////////  CLEARCOAT PROCESS /////////////////////////

begin P_clearcoat arriving
	travel to conv.sta_clearcoat
	move into Q_clearcoat
	use R_clearcoat for normal 2,0.3 min
	move into conv.sta_clearcoat
	travel to conv.sta_stamping_(V_type_ID)
	send to P_stamping(V_type_ID)
end

///////////////////////--------------------/////////////////////////


///////////////////////  STAMPING PROCESS /////////////////////////

begin P_stamping arriving
	move into Q_stamping(procindex)	
	use R_stamping(procindex) for 3 min
	move into conv.sta_stamping_(procindex)
	
	set this load type = L_prod(procindex)
	
	travel to conv.sta_quality_(procindex)
	send to P_quality(procindex)
end

///////////////////////---------------------/////////////////////////

///////////////////////  QUALITY PROCESS /////////////////////////

begin P_quality arriving
	move into Q_quality(procindex)

	
	use R_quality(procindex) for normal 2,0.4 min
	move into conv.sta_quality_(procindex)
	if V_Random < 1
		begin
			travel to conv.sta_out_(procindex)
			send to P_out(procindex)
		end
	else
		begin
			send to die
		end
end

///////////////////////------------------/////////////////////////

///////////////////////  OUT PROCESS /////////////////////////

begin P_out arriving
	use R_out(procindex) for normal 30,5 sec
	send to P_cluster(procindex)
end

///////////////////////--------------/////////////////////////

/////////////////////// CLUSTER PROCESS /////////////////////////

begin P_cluster arriving
	move into Q_finished_prod(procindex)
	
	

	if Q_finished_prod(procindex) current loads < 5 then
		wait to be ordered on OL_prod(procindex)
	else
		begin
			order 4 loads from OL_prod(procindex) to die
			use R_cluster(procindex) for 30 sec
			
			set load type to L_product_big(procindex)
			move into Q_clusters(procindex)
			send to P_lift(procindex)
		end
	
end

///////////////////////-----------------/////////////////////////


/////////////////////// LIFT PROCESS ///////////////////////// 

begin P_lift arriving	
	if Q_ship current loads < 15 then
		begin
			move into forklift.cp_pick_(procindex)
			travel to forklift.cp_drop
			send to P_ship 
		end 
	else
		begin
			print "Shipping congestion" to message
			wait until Q_ship current loads is 0
			send to P_lift(procindex)
		end
end 

///////////////////////-----------------///////////////////////


/////////////////////// SHIP PROCESS /////////////////////////

begin P_ship arriving
	move into Q_ship
	print "Current load: " Q_ship current loads to L_ship
	if Q_ship current loads < 15 then
		wait to be ordered on OL_prod_ship
	else 
		begin
			if V_truck_isArrived = 1 then 
				begin
					order 14 loads from OL_prod_ship to die
					move into trucks.cp_pick
					travel to trucks.cp_drop
					set V_truck_isArrived to 0
					print "Delay time:   " (ac-V_schedule_truck)/60 as .2 "min" to message
					print "Delay time:   " (ac-V_schedule_truck)/60 as .2 "min" to L_delay
					set V_delay to (ac-V_schedule_truck)/60		
				end		
			else 
				begin
					set V_truck_isArrived to 2
					print "The production finished earlier" to message
					set V_schedule_truck to ac
					wait to be ordered on OL_prod_ship
					
				end
						
		end
	send to die	
end

///////////////////////-----------------///////////////////////


/////////////////////// TRUCK SCHEDULE PROCESS /////////////////////////

begin P_truck_schedule arriving
	print "Truck sent" to message
	move into trucks.cp_pick	
	if V_truck_isArrived = 0 then
		begin 
			set V_truck_isArrived to 1
			print "Truck has arrived" to message
			set V_schedule_truck to ac
		end
	else 
		begin	
			order 15 loads from OL_prod_ship to die
			print "Anticipation time:   " (ac-V_schedule_truck)/60 as .2 "min" to message
			print "Anticipation time:   " (ac-V_schedule_truck)/60 as .2 "min" to L_delay	
			set V_delay to (V_schedule_truck-ac)/60
			move into trucks.cp_pick
			travel to trucks.cp_drop
			set V_truck_isArrived to 0	
		end
end

///////////////////////-----------------///////////////////////


/////////////////////// STOP PRODUCTION PROCESS /////////////////////////

begin P_stop_production arriving
	increment V_stop_production by 1
end

///////////////////////-----------------///////////////////////

