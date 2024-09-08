// logic.c
// AutoMod® 14.6 Generated File
// Build: 14.6.0.5
// Model name:	automod_proj_queues
// Model path:	C:\Users\dnasc\Downloads\Nuova cartella (29)\Simulation 1\automod_proj_queues.dir\
// Generated:	Mon Jan 29 23:43:09 2024
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


#include "cdecls.h"


static int32
P_read_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			am2_V_pointer = OpenFilePtr(am_model.$sys, "dir/input.csv", "r");
		}
				{
			if (isFileValid(am2_V_pointer, 1)) {
				int rflag;
				static ReadRef st1;
				static ReadRef st2;
				static ReadRef st3;

				setupReadRef(&st1, 0, am_model.am_V_useless$var, &am2_V_useless[1], NULL, -1, FALSE);
				setupReadRef(&st2, 0, am_model.am_V_useless$var, &am2_V_useless[2], NULL, -1, FALSE);
				setupReadRef(&st3, 0, am_model.am_V_useless$var, &am2_V_useless[3], NULL, -1, FALSE);
				rflag = readFile(am2_V_pointer->fp, ";", &st1, &st2, &st3, NULL);
				SetFileAtEof(am2_V_pointer, EOF, rflag);
			}
		}
		{
			while (am2_V_stop_production < 1) {
								{
					if (isFileValid(am2_V_pointer, 1)) {
						int rflag;
						static ReadRef st1;
						static ReadRef st2;
						static ReadRef st3;

						setupReadRef(&st1, 1, am_model.am_V_id$att, &thisObj->attribute->am2_V_id, NULL, -1, FALSE);
						setupReadRef(&st2, 1, am_model.am_V_type$att, &thisObj->attribute->am2_V_type, NULL, -1, FALSE);
						setupReadRef(&st3, 1, am_model.am_V_rugos$att, &thisObj->attribute->am2_V_rugos, NULL, -1, FALSE);
						rflag = readFile(am2_V_pointer->fp, ";", &st1, &st2, &st3, NULL);
						SetFileAtEof(am2_V_pointer, EOF, rflag);
						if (rflag == EOF) {
							{
								{
									char* pArg1 = " My input file is fully read";

									message("%s", pArg1);
								}
							}
							{
								thisObj->nextproc = am2_die; /* send to ... */
								EntityChanged(W_LOAD);
								retval = Continue;
								goto LabelRet;
							}
						}
					}
				}
				{
					if (waitfor(ToModelTime(normal1(am2_stream0, 150, 5), UNITSECONDS), thisObj, P_read_arriving, Step 2, am_localargs) == Delayed)
						return Delayed;
Label2: ; // Step 2
				}
				{
					thisObj->attribute->am2_V_start_time = FromModelTime(ASIclock, UNITSECONDS);
					EntityChanged(0x00000040);
				}
				{
					clone(thisObj, 1, am2_P_init, NULL);
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_read_arriving


typedef struct {
	double freq;
	int32 value;
} Oneof0;

static Oneof0 List0[] = {
	{ 10, 10},
	{ 100, 0}
};

static int32
oneofFunc0(load* thisObj)
{
	int ind = 0;
	Oneof0* list = List0;
	double sample = getdrand(am2_stream0) * 100;

	while (list->freq < sample) {
		ind++;
		list++;
	}
	return List0[ind].value;
}

static int32
P_init_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			LdSetType(thisObj, am2_L_prod_init);
			EntityChanged(0x00000040);
		}
		{
			if (StringCompare(thisObj->attribute->am2_V_type, "Left") == 0) {
				thisObj->attribute->am2_V_type_ID = 1;
				EntityChanged(0x00000040);
			}
		}
		{
			if (StringCompare(thisObj->attribute->am2_V_type, "Right") == 0) {
				thisObj->attribute->am2_V_type_ID = 2;
				EntityChanged(0x00000040);
			}
		}
		{
			pushppa(thisObj, P_init_arriving, Step 2, am_localargs);
			pushppa(thisObj, inqueue, Step 1, am2_Q_in);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			pushppa(thisObj, P_init_arriving, Step 3, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_conv.am_sta_in, -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label3: ; // Step 3
		}
		{
			thisObj->attribute->am2_V_Random = oneofFunc0(thisObj);
			EntityChanged(0x00000040);
		}
		{
			thisObj->nextproc = &(am2_P_polish[1]); /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_init_arriving

static int32
P_polish_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_polish_arriving, Step 2, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_polishing_", CurProcIndex(), -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label2: ; // Step 2
		}
		{
			pushppa(thisObj, P_polish_arriving, Step 3, am_localargs);
			pushppa(thisObj, inqueue, Step 1, &(am2_Q_polishing[ValidIndex("am_model.am_Q_polishing", CurProcIndex(), 3)]));
			return Continue; // go move into territory
Label3: ; // Step 3
		}
		{
			return usefor(&(am2_R_polishing[ValidIndex("am_model.am_R_polishing", CurProcIndex(), 3)]), 1, thisObj, P_polish_arriving, Step 4, am_localargs, ToModelTime(normal1(am2_stream0, 5.5000000000000000 * (1 + (thisObj->attribute->am2_V_rugos / 100)), 0.50000000000000000), UNITMINUTES));
Label4: ; // Step 4
		}
		{
			pushppa(thisObj, P_polish_arriving, Step 5, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_polishing_", CurProcIndex(), -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label5: ; // Step 5
		}
		{
			thisObj->nextproc = &(am2_P_painting[ValidIndex("am_model.am_P_painting", CurProcIndex(), 2)]); /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_polish_arriving

static int32
P_painting_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_painting_arriving, Step 2, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_painting_", CurProcIndex(), -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label2: ; // Step 2
		}
		{
			pushppa(thisObj, P_painting_arriving, Step 3, am_localargs);
			pushppa(thisObj, inqueue, Step 1, &(am2_Q_painting[ValidIndex("am_model.am_Q_painting", CurProcIndex(), 2)]));
			return Continue; // go move into territory
Label3: ; // Step 3
		}
		{
			return usefor(&(am2_R_painting[ValidIndex("am_model.am_R_painting", CurProcIndex(), 2)]), 1, thisObj, P_painting_arriving, Step 4, am_localargs, ToModelTime(4, UNITMINUTES));
Label4: ; // Step 4
		}
		{
			pushppa(thisObj, P_painting_arriving, Step 5, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_painting_", CurProcIndex(), -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label5: ; // Step 5
		}
		{
			thisObj->nextproc = am2_P_drying; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_painting_arriving

static int32
P_drying_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_drying_arriving, Step 2, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_conv.am_sta_drying, -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label2: ; // Step 2
		}
		{
			pushppa(thisObj, P_drying_arriving, Step 3, am_localargs);
			pushppa(thisObj, inqueue, Step 1, am2_Q_drying);
			return Continue; // go move into territory
Label3: ; // Step 3
		}
		{
			return usefor(am2_R_drying, 1, thisObj, P_drying_arriving, Step 4, am_localargs, ToModelTime(2, UNITMINUTES));
Label4: ; // Step 4
		}
		{
			pushppa(thisObj, P_drying_arriving, Step 5, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_conv.am_sta_drying, -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label5: ; // Step 5
		}
		{
			thisObj->nextproc = am2_P_clearcoat; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_drying_arriving

static int32
P_clearcoat_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_clearcoat_arriving, Step 2, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_conv.am_sta_clearcoat, -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label2: ; // Step 2
		}
		{
			pushppa(thisObj, P_clearcoat_arriving, Step 3, am_localargs);
			pushppa(thisObj, inqueue, Step 1, am2_Q_clearcoat);
			return Continue; // go move into territory
Label3: ; // Step 3
		}
		{
			return usefor(am2_R_clearcoat, 1, thisObj, P_clearcoat_arriving, Step 4, am_localargs, ToModelTime(normal1(am2_stream0, 2, 0.29999999999999999), UNITMINUTES));
Label4: ; // Step 4
		}
		{
			pushppa(thisObj, P_clearcoat_arriving, Step 5, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_conv.am_sta_clearcoat, -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label5: ; // Step 5
		}
		{
			pushppa(thisObj, P_clearcoat_arriving, Step 6, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_stamping_", thisObj->attribute->am2_V_type_ID, -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label6: ; // Step 6
		}
		{
			thisObj->nextproc = &(am2_P_stamping[ValidIndex("am_model.am_P_stamping", thisObj->attribute->am2_V_type_ID, 2)]); /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_clearcoat_arriving

static int32
P_stamping_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_stamping_arriving, Step 2, am_localargs);
			pushppa(thisObj, inqueue, Step 1, &(am2_Q_stamping[ValidIndex("am_model.am_Q_stamping", CurProcIndex(), 2)]));
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			return usefor(&(am2_R_stamping[ValidIndex("am_model.am_R_stamping", CurProcIndex(), 2)]), 1, thisObj, P_stamping_arriving, Step 3, am_localargs, ToModelTime(3, UNITMINUTES));
Label3: ; // Step 3
		}
		{
			pushppa(thisObj, P_stamping_arriving, Step 4, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_stamping_", CurProcIndex(), -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label4: ; // Step 4
		}
		{
			LdSetType(thisObj, &(am2_L_prod[ValidIndex("am_model.am_L_prod", CurProcIndex(), 2)]));
			EntityChanged(0x00000040);
		}
		{
			pushppa(thisObj, P_stamping_arriving, Step 5, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_quality_", CurProcIndex(), -9999));
			pushppa(thisObj, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label5: ; // Step 5
		}
		{
			thisObj->nextproc = &(am2_P_quality[ValidIndex("am_model.am_P_quality", CurProcIndex(), 2)]); /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_stamping_arriving

static int32
P_quality_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_quality_arriving, Step 2, am_localargs);
			pushppa(thisObj, inqueue, Step 1, &(am2_Q_quality[ValidIndex("am_model.am_Q_quality", CurProcIndex(), 2)]));
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			return usefor(&(am2_R_quality[ValidIndex("am_model.am_R_quality", CurProcIndex(), 2)]), 1, thisObj, P_quality_arriving, Step 3, am_localargs, ToModelTime(normal1(am2_stream0, 2, 0.40000000000000002), UNITMINUTES));
Label3: ; // Step 3
		}
		{
			pushppa(thisObj, P_quality_arriving, Step 4, am_localargs);
			load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_quality_", CurProcIndex(), -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label4: ; // Step 4
		}
		{
			if (thisObj->attribute->am2_V_Random < 1) {
				{
					pushppa(thisObj, P_quality_arriving, Step 5, am_localargs);
					load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_conv.$sys, "sta_out_", CurProcIndex(), -9999));
					pushppa(thisObj, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label5: ; // Step 5
				}
				{
					thisObj->nextproc = &(am2_P_out[ValidIndex("am_model.am_P_out", CurProcIndex(), 2)]); /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
			else {
				{
					thisObj->nextproc = am2_die; /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_quality_arriving

static int32
P_out_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			return usefor(&(am2_R_out[ValidIndex("am_model.am_R_out", CurProcIndex(), 2)]), 1, thisObj, P_out_arriving, Step 2, am_localargs, ToModelTime(normal1(am2_stream0, 30, 5), UNITSECONDS));
Label2: ; // Step 2
		}
		{
			thisObj->nextproc = &(am2_P_cluster[ValidIndex("am_model.am_P_cluster", CurProcIndex(), 2)]); /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_out_arriving

static int32
P_cluster_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_cluster_arriving, Step 2, am_localargs);
			pushppa(thisObj, inqueue, Step 1, &(am2_Q_finished_prod[ValidIndex("am_model.am_Q_finished_prod", CurProcIndex(), 2)]));
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			if (QueGetCurConts(ValidPtr(&(am2_Q_finished_prod[ValidIndex("am_model.am_Q_finished_prod", CurProcIndex(), 2)]), 51, queue*)) < 5) {
				return waitorder(&(am2_OL_prod[ValidIndex("am_model.am_OL_prod", CurProcIndex(), 2)]), thisObj, P_cluster_arriving, Step 3, am_localargs);
Label3: ; // Step 3
				if (!thisObj->inLeaveProc && thisObj->nextproc) {
					retval = Continue;
					goto LabelRet;
				}
			}
			else {
				{
					order(4, &(am2_OL_prod[ValidIndex("am_model.am_OL_prod", CurProcIndex(), 2)]), am2_die, NULL);		// Place an order
				}
				{
					return usefor(&(am2_R_cluster[ValidIndex("am_model.am_R_cluster", CurProcIndex(), 2)]), 1, thisObj, P_cluster_arriving, Step 4, am_localargs, ToModelTime(30, UNITSECONDS));
Label4: ; // Step 4
				}
				{
					LdSetType(thisObj, &(am2_L_product_big[ValidIndex("am_model.am_L_product_big", CurProcIndex(), 2)]));
					EntityChanged(0x00000040);
				}
				{
					pushppa(thisObj, P_cluster_arriving, Step 5, am_localargs);
					pushppa(thisObj, inqueue, Step 1, &(am2_Q_clusters[ValidIndex("am_model.am_Q_clusters", CurProcIndex(), 2)]));
					return Continue; // go move into territory
Label5: ; // Step 5
				}
				{
					thisObj->nextproc = &(am2_P_lift[ValidIndex("am_model.am_P_lift", CurProcIndex(), 2)]); /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_cluster_arriving

static int32
P_lift_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			if (QueGetCurConts(am2_Q_ship) < 15) {
				{
					pushppa(thisObj, P_lift_arriving, Step 2, am_localargs);
					load_SetDestLoc(thisObj, SysGetQualifier(am_model.am_forklift.$sys, "cp_pick_", CurProcIndex(), -9999));
					pushppa(thisObj, move_in_loc, Step 1, NULL);
					return Continue; // go move into territory
Label2: ; // Step 2
				}
				{
					pushppa(thisObj, P_lift_arriving, Step 3, am_localargs);
					load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_forklift.am_cp_drop, -9999));
					pushppa(thisObj, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label3: ; // Step 3
				}
				{
					thisObj->nextproc = am2_P_ship; /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
			else {
				{
					{
						char* pArg1 = "Shipping congestion";

						message("%s", pArg1);
					}
				}
				{
					while (!(QueGetCurConts(am2_Q_ship) == 0)) { // wait until ...
						return waituntil(thisObj, P_lift_arriving, Step 4, am_localargs, 0x00010000);
Label4: ; // Step 4
					}
				}
				{
					thisObj->nextproc = &(am2_P_lift[ValidIndex("am_model.am_P_lift", CurProcIndex(), 2)]); /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_lift_arriving

static int32
P_ship_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			pushppa(thisObj, P_ship_arriving, Step 2, am_localargs);
			pushppa(thisObj, inqueue, Step 1, am2_Q_ship);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			{
				char* pArg1 = "Current load:";
				int32 pArg2 = QueGetCurConts(am2_Q_ship);

				updatelabel(am2_L_ship, "%s%d", pArg1, pArg2);
			}
		}
		{
			if (QueGetCurConts(am2_Q_ship) < 15) {
				return waitorder(am2_OL_prod_ship, thisObj, P_ship_arriving, Step 3, am_localargs);
Label3: ; // Step 3
				if (!thisObj->inLeaveProc && thisObj->nextproc) {
					retval = Continue;
					goto LabelRet;
				}
			}
			else {
				{
					if (am2_V_truck_isArrived == 1) {
						{
							order(14, am2_OL_prod_ship, am2_die, NULL);		// Place an order
						}
						{
							pushppa(thisObj, P_ship_arriving, Step 4, am_localargs);
							load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_trucks.am_cp_pick, -9999));
							pushppa(thisObj, move_in_loc, Step 1, NULL);
							return Continue; // go move into territory
Label4: ; // Step 4
						}
						{
							pushppa(thisObj, P_ship_arriving, Step 5, am_localargs);
							load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_trucks.am_cp_drop, -9999));
							pushppa(thisObj, travel_to_loc, Step 1, NULL);
							return Continue; // go move to location
Label5: ; // Step 5
						}
						{
							am2_V_truck_isArrived = 0;
							EntityChanged(0x01000000);
						}
						{
							{
								char* pArg1 = "Delay time:   ";
								double pArg2 = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
								char* pArg3 = "min";

								message("%s%.2lf%s", pArg1, pArg2, pArg3);
							}
						}
						{
							{
								char* pArg1 = "Delay time:   ";
								double pArg2 = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
								char* pArg3 = "min";

								updatelabel(am2_L_delay, "%s%.2lf%s", pArg1, pArg2, pArg3);
							}
						}
						{
							am2_V_delay = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
							EntityChanged(0x01000000);
						}
					}
					else {
						{
							am2_V_truck_isArrived = 2;
							EntityChanged(0x01000000);
						}
						{
							{
								char* pArg1 = "The production finshed earlier";

								message("%s", pArg1);
							}
						}
						{
							am2_V_schedule_truck = FromModelTime(ASIclock, UNITSECONDS);
							EntityChanged(0x01000000);
						}
						{
							return waitorder(am2_OL_prod_ship, thisObj, P_ship_arriving, Step 6, am_localargs);
Label6: ; // Step 6
							if (!thisObj->inLeaveProc && thisObj->nextproc) {
								retval = Continue;
								goto LabelRet;
							}
						}
					}
				}
			}
		}
		{
			thisObj->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_ship_arriving

static int32
P_truck_schedule_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	switch (step) { // Make the step switcher
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  // Step1
	{
		{
			{
				char* pArg1 = "Truck sent";

				message("%s", pArg1);
			}
		}
		{
			pushppa(thisObj, P_truck_schedule_arriving, Step 2, am_localargs);
			load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_trucks.am_cp_pick, -9999));
			pushppa(thisObj, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			if (am2_V_truck_isArrived == 0) {
				{
					am2_V_truck_isArrived = 1;
					EntityChanged(0x01000000);
				}
				{
					{
						char* pArg1 = "Truck has arrived";

						message("%s", pArg1);
					}
				}
				{
					am2_V_schedule_truck = FromModelTime(ASIclock, UNITSECONDS);
					EntityChanged(0x01000000);
				}
			}
			else {
				{
					order(15, am2_OL_prod_ship, am2_die, NULL);		// Place an order
				}
				{
					{
						char* pArg1 = "Delay time:   ";
						double pArg2 = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
						char* pArg3 = "min";

						message("%s%.2lf%s", pArg1, pArg2, pArg3);
					}
				}
				{
					{
						char* pArg1 = "Delay time:   ";
						double pArg2 = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
						char* pArg3 = "min";

						updatelabel(am2_L_delay, "%s%.2lf%s", pArg1, pArg2, pArg3);
					}
				}
				{
					am2_V_delay = (FromModelTime(ASIclock, UNITSECONDS) - am2_V_schedule_truck) / 60;
					EntityChanged(0x01000000);
				}
				{
					pushppa(thisObj, P_truck_schedule_arriving, Step 3, am_localargs);
					load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_trucks.am_cp_pick, -9999));
					pushppa(thisObj, move_in_loc, Step 1, NULL);
					return Continue; // go move into territory
Label3: ; // Step 3
				}
				{
					pushppa(thisObj, P_truck_schedule_arriving, Step 4, am_localargs);
					load_SetDestLoc(thisObj, LocGetQualifier(am_model.am_trucks.am_cp_drop, -9999));
					pushppa(thisObj, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label4: ; // Step 4
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_truck_schedule_arriving

static int32
P_stop_production_arriving(load* thisObj, int32 step, void* args)
{
	void* am_localargs = INIT_Pointer;
	int32 retval = Continue;
	{
		{
			am2_V_stop_production += 1;
			EntityChanged(0x01000000);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} // end of P_stop_production_arriving



/* init function for logic.m */
void
model_logic_init(struct model_struct* data)
{
	data->am_P_read->aprc = P_read_arriving;
	data->am_P_init->aprc = P_init_arriving;
	data->am_P_polish->aprc = P_polish_arriving;
	data->am_P_painting->aprc = P_painting_arriving;
	data->am_P_drying->aprc = P_drying_arriving;
	data->am_P_clearcoat->aprc = P_clearcoat_arriving;
	data->am_P_stamping->aprc = P_stamping_arriving;
	data->am_P_quality->aprc = P_quality_arriving;
	data->am_P_out->aprc = P_out_arriving;
	data->am_P_cluster->aprc = P_cluster_arriving;
	data->am_P_lift->aprc = P_lift_arriving;
	data->am_P_ship->aprc = P_ship_arriving;
	data->am_P_truck_schedule->aprc = P_truck_schedule_arriving;
	data->am_P_stop_production->aprc = P_stop_production_arriving;
}

