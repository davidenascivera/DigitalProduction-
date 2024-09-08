// automod_proj_sim_3~init1.c
// AutoMod® 14.6 Generated File
// Build: 14.6.0.5
// Model name:	automod_proj_sim_3
// Model path:	C:\Users\dnasc\Downloads\Nuova cartella (29)\Simulation 3\automod_proj_sim_3.dir\
// Generated:	Mon Jan 29 23:49:08 2024
// Applied/AutoMod Licensee Confidential
// NO DISTRIBUTION OR REPRODUCTION RIGHTS GRANTED!
// Copyright © 1988-2022 Applied Materials. All rights reserved.
//
// All Rights Reserved.  Reproduction or transmission in whole or
// in part, in any form or by any means, electronic, mechanical or
// otherwise, is prohibited without the prior written consent of
// copyright owner.
//
// Licensed Material - Property of Applied Materials, Inc.
//
// Applied Materials, Inc.
// 3050 Bowers Drive
// P.O. Box 58039
// Santa Clara, CA 95054-3299
// U.S.A.
//


#include "decls.h"

void
initglobs0(void)
{
	am_model.$sys = model;
	am_model.am_conv.$sys = symGetSystemDataByName(am_model.$sys, "conv");
	am_model.am_conv.am_sta_in = symGetSystemDataByName(am_model.am_conv.$sys, "sta_in");
	am_model.am_conv.am_sta_out_1 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_out_1");
	am_model.am_conv.am_sta_drying = symGetSystemDataByName(am_model.am_conv.$sys, "sta_drying");
	am_model.am_conv.am_sta_polishing_1 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_polishing_1");
	am_model.am_conv.am_sta_polishing_2 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_polishing_2");
	am_model.am_conv.am_parentsys = symGetSystemDataByName(am_model.am_conv.$sys, "parentsys");
	am_model.am_conv.am_sta_clearcoat = symGetSystemDataByName(am_model.am_conv.$sys, "sta_clearcoat");
	am_model.am_conv.am_sta_out_2 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_out_2");
	am_model.am_conv.am_sta_quality_2 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_quality_2");
	am_model.am_conv.am_sta_stamping_1 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_stamping_1");
	am_model.am_conv.am_sta_painting_2 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_painting_2");
	am_model.am_conv.am_sta_painting_1 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_painting_1");
	am_model.am_conv.am_sta_stamping_2 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_stamping_2");
	am_model.am_conv.am_sta_quality_1 = symGetSystemDataByName(am_model.am_conv.$sys, "sta_quality_1");
	am_model.am_forklift.$sys = symGetSystemDataByName(am_model.$sys, "forklift");
	am_model.am_forklift.am_cp_pick_1 = symGetSystemDataByName(am_model.am_forklift.$sys, "cp_pick_1");
	am_model.am_forklift.am_cp_pick_2 = symGetSystemDataByName(am_model.am_forklift.$sys, "cp_pick_2");
	am_model.am_forklift.am_cp_drop = symGetSystemDataByName(am_model.am_forklift.$sys, "cp_drop");
	am_model.am_forklift.am_cp_park = symGetSystemDataByName(am_model.am_forklift.$sys, "cp_park");
	am_model.am_forklift.am_forklift = symGetSystemDataByName(am_model.am_forklift.$sys, "forklift");
	am_model.am_forklift.am_forklift_vehicle = symGetSystemDataByName(am_model.am_forklift.$sys, "forklift_vehicle");
	am_model.am_forklift.am_parentsys = symGetSystemDataByName(am_model.am_forklift.$sys, "parentsys");
	am_model.am_trucks.$sys = symGetSystemDataByName(am_model.$sys, "trucks");
	am_model.am_trucks.am_truck = symGetSystemDataByName(am_model.am_trucks.$sys, "truck");
	am_model.am_trucks.am_cp_pick = symGetSystemDataByName(am_model.am_trucks.$sys, "cp_pick");
	am_model.am_trucks.am_cp_drop = symGetSystemDataByName(am_model.am_trucks.$sys, "cp_drop");
	am_model.am_trucks.am_cp_park = symGetSystemDataByName(am_model.am_trucks.$sys, "cp_park");
	am_model.am_trucks.am_truck_vehicle = symGetSystemDataByName(am_model.am_trucks.$sys, "truck_vehicle");
	am_model.am_trucks.am_parentsys = symGetSystemDataByName(am_model.am_trucks.$sys, "parentsys");
	am_model.am_V_delay$var = symGetSystemDataByName(am_model.$sys, "V_delay");
	am_model.am_V_delay$var->data = (void*)&am_model.am_V_delay;
	am_model.am_stream_L_truck_1 = symGetSystemDataByName(am_model.$sys, "stream_L_truck_1");
	am_model.am_die = symGetSystemDataByName(am_model.$sys, "die");
	am_model.am_L_delay = symGetSystemDataByName(am_model.$sys, "L_delay");
	am_model.am_stream_R_polishing_1 = symGetSystemDataByName(am_model.$sys, "stream_R_polishing_1");
	am_model.am_L_prod_init = symGetSystemDataByName(am_model.$sys, "L_prod_init");
	am_model.am_stream_L_stop_production_1 = symGetSystemDataByName(am_model.$sys, "stream_L_stop_production_1");
	am_model.am_stream_R_stamping_1 = symGetSystemDataByName(am_model.$sys, "stream_R_stamping_1");
	am_model.am_P_read = symGetSystemDataByName(am_model.$sys, "P_read");
	am_model.am_R_quality = symGetSystemDataByName(am_model.$sys, "R_quality");
	am_model.am_Q_quality = symGetSystemDataByName(am_model.$sys, "Q_quality");
	am_model.am_P_quality = symGetSystemDataByName(am_model.$sys, "P_quality");
	am_model.am_stream_R_quality_1 = symGetSystemDataByName(am_model.$sys, "stream_R_quality_1");
	am_model.am_OPCTimestamp$var = symGetSystemDataByName(am_model.$sys, "OPCTimestamp");
	am_model.am_OPCTimestamp$var->data = (void*)&am_model.am_OPCTimestamp;
	am_model.am_L_prod = symGetSystemDataByName(am_model.$sys, "L_prod");
	am_model.am_P_polish = symGetSystemDataByName(am_model.$sys, "P_polish");
	am_model.am_R_drying = symGetSystemDataByName(am_model.$sys, "R_drying");
	am_model.am_R_out = symGetSystemDataByName(am_model.$sys, "R_out");
	am_model.am_Q_drying = symGetSystemDataByName(am_model.$sys, "Q_drying");
	am_model.am_P_drying = symGetSystemDataByName(am_model.$sys, "P_drying");
	am_model.am_P_out = symGetSystemDataByName(am_model.$sys, "P_out");
	am_model.am_V_type$att = symGetSystemDataByName(am_model.$sys, "V_type");
	am_model.am_stream_R_cluster_1 = symGetSystemDataByName(am_model.$sys, "stream_R_cluster_1");
	am_model.am_V_useless$var = symGetSystemDataByName(am_model.$sys, "V_useless");
	am_model.am_V_useless = (char**)xcalloc(5, sizeof(*am_model.am_V_useless));
	am_model.am_V_useless$var->data = (void*)am_model.am_V_useless;
	am_model.am_Q_finished_prod = symGetSystemDataByName(am_model.$sys, "Q_finished_prod");
	am_model.am_stream_R_out_1 = symGetSystemDataByName(am_model.$sys, "stream_R_out_1");
	am_model.am_R_polishing = symGetSystemDataByName(am_model.$sys, "R_polishing");
	am_model.am_Q_polishing = symGetSystemDataByName(am_model.$sys, "Q_polishing");
	am_model.am_modelsys = symGetSystemDataByName(am_model.$sys, "modelsys");
	am_model.am_stream_R_clearcoat_1 = symGetSystemDataByName(am_model.$sys, "stream_R_clearcoat_1");
	am_model.am_V_pointer$var = symGetSystemDataByName(am_model.$sys, "V_pointer");
	am_model.am_V_pointer$var->data = (void*)&am_model.am_V_pointer;
	am_model.am_stream_R_painting_1 = symGetSystemDataByName(am_model.$sys, "stream_R_painting_1");
	am_model.am_OL_prod_ship = symGetSystemDataByName(am_model.$sys, "OL_prod_ship");
	am_model.am_Space = symGetSystemDataByName(am_model.$sys, "Space");
	am_model.am_Q_clusters = symGetSystemDataByName(am_model.$sys, "Q_clusters");
	am_model.am_V_id$att = symGetSystemDataByName(am_model.$sys, "V_id");
	am_model.am_V_truck_isArrived$var = symGetSystemDataByName(am_model.$sys, "V_truck_isArrived");
	am_model.am_V_truck_isArrived$var->data = (void*)&am_model.am_V_truck_isArrived;
	am_model.am_R_stamping = symGetSystemDataByName(am_model.$sys, "R_stamping");
	am_model.am_Q_painting = symGetSystemDataByName(am_model.$sys, "Q_painting");
	am_model.am_R_painting = symGetSystemDataByName(am_model.$sys, "R_painting");
	am_model.am_Q_stamping = symGetSystemDataByName(am_model.$sys, "Q_stamping");
	am_model.am_P_stamping = symGetSystemDataByName(am_model.$sys, "P_stamping");
	am_model.am_P_painting = symGetSystemDataByName(am_model.$sys, "P_painting");
	am_model.am_stream_L_dummy_1 = symGetSystemDataByName(am_model.$sys, "stream_L_dummy_1");
	am_model.am_L_product_big = symGetSystemDataByName(am_model.$sys, "L_product_big");
	am_model.am_stream0 = symGetSystemDataByName(am_model.$sys, "stream0");
	am_model.am_stream_R_drying_1 = symGetSystemDataByName(am_model.$sys, "stream_R_drying_1");
	am_model.am_parentsys = NULL;
	am_model.am_P_init = symGetSystemDataByName(am_model.$sys, "P_init");
	am_model.am_V_stop_production$var = symGetSystemDataByName(am_model.$sys, "V_stop_production");
	am_model.am_V_stop_production$var->data = (void*)&am_model.am_V_stop_production;
	am_model.am_P_stop_production = symGetSystemDataByName(am_model.$sys, "P_stop_production");
	am_model.am_OL_prod = symGetSystemDataByName(am_model.$sys, "OL_prod");
	am_model.am_V_Random$att = symGetSystemDataByName(am_model.$sys, "V_Random");
	am_model.am_Q_in = symGetSystemDataByName(am_model.$sys, "Q_in");
	am_model.am_P_lift = symGetSystemDataByName(am_model.$sys, "P_lift");
	am_model.am_P_truck_schedule = symGetSystemDataByName(am_model.$sys, "P_truck_schedule");
	am_model.am_V_schedule_truck$var = symGetSystemDataByName(am_model.$sys, "V_schedule_truck");
	am_model.am_V_schedule_truck$var->data = (void*)&am_model.am_V_schedule_truck;
	am_model.am_Q_ship = symGetSystemDataByName(am_model.$sys, "Q_ship");
	am_model.am_P_ship = symGetSystemDataByName(am_model.$sys, "P_ship");
	am_model.am_R_cluster = symGetSystemDataByName(am_model.$sys, "R_cluster");
	am_model.am_L_ship = symGetSystemDataByName(am_model.$sys, "L_ship");
	am_model.am_OPCQuality$var = symGetSystemDataByName(am_model.$sys, "OPCQuality");
	am_model.am_OPCQuality$var->data = (void*)&am_model.am_OPCQuality;
	am_model.am_P_cluster = symGetSystemDataByName(am_model.$sys, "P_cluster");
	am_model.am_V_start_time$att = symGetSystemDataByName(am_model.$sys, "V_start_time");
	am_model.am_V_type_ID$att = symGetSystemDataByName(am_model.$sys, "V_type_ID");
	am_model.am_P_clearcoat = symGetSystemDataByName(am_model.$sys, "P_clearcoat");
	am_model.am_V_rugos$att = symGetSystemDataByName(am_model.$sys, "V_rugos");
	am_model.am_Q_clearcoat = symGetSystemDataByName(am_model.$sys, "Q_clearcoat");
	am_model.am_R_clearcoat = symGetSystemDataByName(am_model.$sys, "R_clearcoat");
	model_logic_init(&am_model);
	{
		Iter(List, FileList) it = Begin(List, FileList, &((ProcSystem*)am_model.$sys)->files);

	}
	{
		Iter(List, AMTypeList) it = Begin(List, AMTypeList, &((ProcSystem*)am_model.$sys)->types);

		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Acceleration);
		IterValue(List, AMTypeList, it)->valstrfunc = Acceleration_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AlignmentValue);
		IterValue(List, AMTypeList, it)->valstrfunc = AlignmentValue_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(block*);
		IterValue(List, AMTypeList, it)->valstrfunc = BlockPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))BlockPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMBlockList*);
		IterValue(List, AMTypeList, it)->valstrfunc = BlockList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ASI_Color);
		IterValue(List, AMTypeList, it)->valstrfunc = Color_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))Color_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Container*);
		IterValue(List, AMTypeList, it)->valstrfunc = ContainerPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))ContainerPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMContainerList*);
		IterValue(List, AMTypeList, it)->valstrfunc = ContainerList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(counter*);
		IterValue(List, AMTypeList, it)->valstrfunc = CounterPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))CounterPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Distance);
		IterValue(List, AMTypeList, it)->valstrfunc = Distance_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(iofile*);
		IterValue(List, AMTypeList, it)->valstrfunc = FilePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))FilePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(bgraph*);
		IterValue(List, AMTypeList, it)->valstrfunc = GraphPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))GraphPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(int32);
		IterValue(List, AMTypeList, it)->valstrfunc = Integer_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMIntegerList*);
		IterValue(List, AMTypeList, it)->valstrfunc = IntegerList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(label*);
		IterValue(List, AMTypeList, it)->valstrfunc = LabelPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))LabelPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(load*);
		IterValue(List, AMTypeList, it)->valstrfunc = LoadPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))LoadPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMLoadList*);
		IterValue(List, AMTypeList, it)->valstrfunc = LoadList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(loadtype*);
		IterValue(List, AMTypeList, it)->valstrfunc = LoadTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))LoadTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(simloc*);
		IterValue(List, AMTypeList, it)->valstrfunc = Location_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))Location_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMLocationList*);
		IterValue(List, AMTypeList, it)->valstrfunc = LocationList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(LocationType*);
		IterValue(List, AMTypeList, it)->valstrfunc = LocationTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))LocationTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMLocationTypeList*);
		IterValue(List, AMTypeList, it)->valstrfunc = LocationTypeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(State_machine*);
		IterValue(List, AMTypeList, it)->valstrfunc = MonitorPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))MonitorPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ConvMotor*);
		IterValue(List, AMTypeList, it)->valstrfunc = MotorPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))MotorPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMConvMotorList*);
		IterValue(List, AMTypeList, it)->valstrfunc = MotorList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(MotorType*);
		IterValue(List, AMTypeList, it)->valstrfunc = MotorTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))MotorTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMMotorTypeList*);
		IterValue(List, AMTypeList, it)->valstrfunc = MotorTypeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ordlist*);
		IterValue(List, AMTypeList, it)->valstrfunc = OrderListPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))OrderListPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Path*);
		IterValue(List, AMTypeList, it)->valstrfunc = PathPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))PathPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMPathList*);
		IterValue(List, AMTypeList, it)->valstrfunc = PathList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AgvPathType*);
		IterValue(List, AMTypeList, it)->valstrfunc = PathTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))PathTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMAgvPathTypeList*);
		IterValue(List, AMTypeList, it)->valstrfunc = PathTypeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Photoeye*);
		IterValue(List, AMTypeList, it)->valstrfunc = PhotoeyePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))PhotoeyePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMPhotoList*);
		IterValue(List, AMTypeList, it)->valstrfunc = PhotoeyeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(PhotoeyeType*);
		IterValue(List, AMTypeList, it)->valstrfunc = PhotoeyeTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))PhotoeyeTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMPhotoeyeTypeList*);
		IterValue(List, AMTypeList, it)->valstrfunc = PhotoeyeTypeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(process*);
		IterValue(List, AMTypeList, it)->valstrfunc = ProcessPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))ProcessPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(queue*);
		IterValue(List, AMTypeList, it)->valstrfunc = QueuePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))QueuePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMQueueList*);
		IterValue(List, AMTypeList, it)->valstrfunc = QueueList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Rate);
		IterValue(List, AMTypeList, it)->valstrfunc = Rate_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(double);
		IterValue(List, AMTypeList, it)->valstrfunc = Real_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(resource*);
		IterValue(List, AMTypeList, it)->valstrfunc = ResourcePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))ResourcePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMResourceList*);
		IterValue(List, AMTypeList, it)->valstrfunc = ResourceList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(SchedJob*);
		IterValue(List, AMTypeList, it)->valstrfunc = SchedJobPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))SchedJobPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMSchedJobList*);
		IterValue(List, AMTypeList, it)->valstrfunc = SchedJobList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ConvSection*);
		IterValue(List, AMTypeList, it)->valstrfunc = SectionPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))SectionPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMConvSectionList*);
		IterValue(List, AMTypeList, it)->valstrfunc = SectionList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ConvSectionType*);
		IterValue(List, AMTypeList, it)->valstrfunc = SectionTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))SectionTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMConvSectionTypeList*);
		IterValue(List, AMTypeList, it)->valstrfunc = SectionTypeList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(States*);
		IterValue(List, AMTypeList, it)->valstrfunc = StatePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))StatePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(rnstream*);
		IterValue(List, AMTypeList, it)->valstrfunc = StreamPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))StreamPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(char*);
		IterValue(List, AMTypeList, it)->valstrfunc = String_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMStringList*);
		IterValue(List, AMTypeList, it)->valstrfunc = StringList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(System*);
		IterValue(List, AMTypeList, it)->valstrfunc = SystemPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))SystemPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(table*);
		IterValue(List, AMTypeList, it)->valstrfunc = TablePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))TablePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ASITime);
		IterValue(List, AMTypeList, it)->valstrfunc = Time_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(ConvTransfer*);
		IterValue(List, AMTypeList, it)->valstrfunc = TransferPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))TransferPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(TransferType*);
		IterValue(List, AMTypeList, it)->valstrfunc = TransferTypePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))TransferTypePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(vehicle*);
		IterValue(List, AMTypeList, it)->valstrfunc = VehiclePtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))VehiclePtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMVehicleList*);
		IterValue(List, AMTypeList, it)->valstrfunc = VehicleList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(VehSeg*);
		IterValue(List, AMTypeList, it)->valstrfunc = VehSegPtr_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc  = (void (*)(char*))VehSegPtr_strvalfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(AMVehSegList*);
		IterValue(List, AMTypeList, it)->valstrfunc = VehSegList_valstrfunc;
		IterInc(List, AMTypeList, it);
		IterValue(List, AMTypeList, it)->size = sizeof(Velocity);
		IterValue(List, AMTypeList, it)->valstrfunc = Velocity_valstrfunc;
		IterValue(List, AMTypeList, it)->strvalfunc = str2String;
	}

}

