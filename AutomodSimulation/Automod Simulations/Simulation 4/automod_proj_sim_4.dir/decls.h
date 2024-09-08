// decls.h
// AutoMod® 14.6 Generated File
// Build: 14.6.0.5
// Model name:	automod_proj_sim_4
// Model path:	C:\Users\dnasc\Downloads\Nuova cartella (29)\Simulation 4\automod_proj_sim_4.dir\
// Generated:	Mon Jan 29 23:50:44 2024
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


#ifndef __DECLS_H__
#define __DECLS_H__

#include "user.h"
struct model_conv_struct {
	System* $sys;
	LocHead* am_sta_in;
	LocHead* am_sta_out_1;
	LocHead* am_sta_drying;
	LocHead* am_sta_polishing_1;
	LocHead* am_sta_polishing_2;
	System* am_parentsys;
	LocHead* am_sta_clearcoat;
	LocHead* am_sta_out_2;
	LocHead* am_sta_quality_2;
	LocHead* am_sta_polishing_3;
	LocHead* am_sta_stamping_1;
	LocHead* am_sta_painting_2;
	LocHead* am_sta_painting_1;
	LocHead* am_sta_stamping_2;
	LocHead* am_sta_quality_1;
};
struct model_forklift_struct {
	System* $sys;
	LocHead* am_cp_pick_1;
	LocHead* am_cp_pick_2;
	LocHead* am_cp_drop;
	LocHead* am_cp_park;
	VehSegSpec* am_forklift;
	VehType* am_forklift_vehicle;
	System* am_parentsys;
};
struct model_trucks_struct {
	System* $sys;
	VehSegSpec* am_truck;
	LocHead* am_cp_pick;
	LocHead* am_cp_drop;
	LocHead* am_cp_park;
	VehType* am_truck_vehicle;
	System* am_parentsys;
};
char* Acceleration_valstrfunc(void*);
Acceleration Acceleration_strvalfunc(char*);
char* AlignmentValue_valstrfunc(void*);
char* BlockPtr_valstrfunc(void*);
block* BlockPtr_strvalfunc(char*);
char* BlockList_valstrfunc(void*);
char* Color_valstrfunc(void*);
ASI_Color Color_strvalfunc(char*);
char* ContainerPtr_valstrfunc(void*);
Container* ContainerPtr_strvalfunc(char*);
char* ContainerList_valstrfunc(void*);
char* CounterPtr_valstrfunc(void*);
counter* CounterPtr_strvalfunc(char*);
char* Distance_valstrfunc(void*);
Distance Distance_strvalfunc(char*);
char* FilePtr_valstrfunc(void*);
iofile* FilePtr_strvalfunc(char*);
char* GraphPtr_valstrfunc(void*);
bgraph* GraphPtr_strvalfunc(char*);
char* Integer_valstrfunc(void*);
int32 Integer_strvalfunc(char*);
char* IntegerList_valstrfunc(void*);
char* LabelPtr_valstrfunc(void*);
label* LabelPtr_strvalfunc(char*);
char* LoadPtr_valstrfunc(void*);
load* LoadPtr_strvalfunc(char*);
char* LoadList_valstrfunc(void*);
char* LoadTypePtr_valstrfunc(void*);
loadtype* LoadTypePtr_strvalfunc(char*);
char* Location_valstrfunc(void*);
simloc* Location_strvalfunc(char*);
char* LocationList_valstrfunc(void*);
char* LocationTypePtr_valstrfunc(void*);
LocationType* LocationTypePtr_strvalfunc(char*);
char* LocationTypeList_valstrfunc(void*);
char* MonitorPtr_valstrfunc(void*);
State_machine* MonitorPtr_strvalfunc(char*);
char* MotorPtr_valstrfunc(void*);
ConvMotor* MotorPtr_strvalfunc(char*);
char* MotorList_valstrfunc(void*);
char* MotorTypePtr_valstrfunc(void*);
MotorType* MotorTypePtr_strvalfunc(char*);
char* MotorTypeList_valstrfunc(void*);
char* OrderListPtr_valstrfunc(void*);
ordlist* OrderListPtr_strvalfunc(char*);
char* PathPtr_valstrfunc(void*);
Path* PathPtr_strvalfunc(char*);
char* PathList_valstrfunc(void*);
char* PathTypePtr_valstrfunc(void*);
AgvPathType* PathTypePtr_strvalfunc(char*);
char* PathTypeList_valstrfunc(void*);
char* PhotoeyePtr_valstrfunc(void*);
Photoeye* PhotoeyePtr_strvalfunc(char*);
char* PhotoeyeList_valstrfunc(void*);
char* PhotoeyeTypePtr_valstrfunc(void*);
PhotoeyeType* PhotoeyeTypePtr_strvalfunc(char*);
char* PhotoeyeTypeList_valstrfunc(void*);
char* ProcessPtr_valstrfunc(void*);
process* ProcessPtr_strvalfunc(char*);
char* QueuePtr_valstrfunc(void*);
queue* QueuePtr_strvalfunc(char*);
char* QueueList_valstrfunc(void*);
char* Rate_valstrfunc(void*);
Rate Rate_strvalfunc(char*);
char* Real_valstrfunc(void*);
double Real_strvalfunc(char*);
char* ResourcePtr_valstrfunc(void*);
resource* ResourcePtr_strvalfunc(char*);
char* ResourceList_valstrfunc(void*);
char* SchedJobPtr_valstrfunc(void*);
SchedJob* SchedJobPtr_strvalfunc(char*);
char* SchedJobList_valstrfunc(void*);
char* SectionPtr_valstrfunc(void*);
ConvSection* SectionPtr_strvalfunc(char*);
char* SectionList_valstrfunc(void*);
char* SectionTypePtr_valstrfunc(void*);
ConvSectionType* SectionTypePtr_strvalfunc(char*);
char* SectionTypeList_valstrfunc(void*);
char* StatePtr_valstrfunc(void*);
States* StatePtr_strvalfunc(char*);
char* StreamPtr_valstrfunc(void*);
rnstream* StreamPtr_strvalfunc(char*);
char* String_valstrfunc(void*);
char* String_strvalfunc(char*);
char* StringList_valstrfunc(void*);
char* SystemPtr_valstrfunc(void*);
System* SystemPtr_strvalfunc(char*);
char* TablePtr_valstrfunc(void*);
table* TablePtr_strvalfunc(char*);
char* Time_valstrfunc(void*);
ASITime Time_strvalfunc(char*);
char* TransferPtr_valstrfunc(void*);
ConvTransfer* TransferPtr_strvalfunc(char*);
char* TransferTypePtr_valstrfunc(void*);
TransferType* TransferTypePtr_strvalfunc(char*);
char* VehiclePtr_valstrfunc(void*);
vehicle* VehiclePtr_strvalfunc(char*);
char* VehicleList_valstrfunc(void*);
char* VehSegPtr_valstrfunc(void*);
VehSeg* VehSegPtr_strvalfunc(char*);
char* VehSegList_valstrfunc(void*);
char* Velocity_valstrfunc(void*);
Velocity Velocity_strvalfunc(char*);
struct model_struct {
	System* $sys;
	variable* am_V_delay$var;
	double am_V_delay;
	rnstream* am_stream_L_truck_1;
	process* am_die;
	label* am_L_delay;
	rnstream* am_stream_R_polishing_1;
	loadtype* am_L_prod_init;
	rnstream* am_stream_L_stop_production_1;
	rnstream* am_stream_R_stamping_1;
	process* am_P_read;
	resource* am_R_quality;
	queue* am_Q_quality;
	process* am_P_quality;
	rnstream* am_stream_R_quality_1;
	variable* am_OPCTimestamp$var;
	char* am_OPCTimestamp;
	loadtype* am_L_prod;
	process* am_P_polish;
	resource* am_R_drying;
	resource* am_R_out;
	queue* am_Q_drying;
	process* am_P_drying;
	process* am_P_out;
	attribute* am_V_type$att;
	rnstream* am_stream_R_cluster_1;
	variable* am_V_useless$var;
	char* *am_V_useless;
	queue* am_Q_finished_prod;
	rnstream* am_stream_R_out_1;
	resource* am_R_polishing;
	queue* am_Q_polishing;
	System* am_modelsys;
	rnstream* am_stream_R_clearcoat_1;
	variable* am_V_pointer$var;
	iofile* am_V_pointer;
	rnstream* am_stream_R_painting_1;
	ordlist* am_OL_prod_ship;
	queue* am_Space;
	queue* am_Q_clusters;
	attribute* am_V_id$att;
	variable* am_V_truck_isArrived$var;
	int32 am_V_truck_isArrived;
	resource* am_R_stamping;
	queue* am_Q_painting;
	resource* am_R_painting;
	queue* am_Q_stamping;
	process* am_P_stamping;
	struct model_forklift_struct am_forklift;
	process* am_P_painting;
	rnstream* am_stream_L_dummy_1;
	loadtype* am_L_product_big;
	rnstream* am_stream0;
	rnstream* am_stream_R_drying_1;
	System* am_parentsys;
	process* am_P_init;
	variable* am_V_stop_production$var;
	int32 am_V_stop_production;
	process* am_P_stop_production;
	struct model_conv_struct am_conv;
	ordlist* am_OL_prod;
	attribute* am_V_Random$att;
	queue* am_Q_in;
	process* am_P_lift;
	process* am_P_truck_schedule;
	variable* am_V_schedule_truck$var;
	int32 am_V_schedule_truck;
	queue* am_Q_ship;
	process* am_P_ship;
	resource* am_R_cluster;
	label* am_L_ship;
	variable* am_OPCQuality$var;
	int32 am_OPCQuality;
	process* am_P_cluster;
	attribute* am_V_start_time$att;
	attribute* am_V_type_ID$att;
	process* am_P_clearcoat;
	attribute* am_V_rugos$att;
	struct model_trucks_struct am_trucks;
	queue* am_Q_clearcoat;
	resource* am_R_clearcoat;
};
extern struct model_struct am_model;
void initglobs0(void);
#endif // __DECLS_H__
