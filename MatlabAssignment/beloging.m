% check if positioning points are inside geo for each operator 


label_geofencing=cell(size(data_operator,1),1);


for c=1:size(data_operator,1) % loop over operators 
    % when c=1
    label_geofencing{c,1}=zeros(size(data_operator{c,1},1),size(geo,2));  
    

    for i=1:size(geo,2) % loop over all geofenced areas
        
        % Perform smthing -> check if the operator c-th is inside 
        % the i-th geofenced area = geo
        % inpolygon(xq,yq,xv,yv)
        % q information is related to positioning points of my sensors
        % v information contains the vertex of the polygon 
        % both q and v must be a double/float 

        % Positioning points 
        
        xq=table2array(data_operator{c,1}(:,15)); % X position of c-th operators  
        yq=table2array(data_operator{c,1}(:,16)); % Y position of c-th operators 
        
        % Accessing vertex of geo
        
        xv=geo(1,i).Vertices(:,1); 
        yv=geo(1,i).Vertices(:,2);

        label_geofencing{c,1}(:,i)=inpolygon(xq,yq,xv,yv); 

    end 
end 



clearvars -except data_operator label_geofencing geo
