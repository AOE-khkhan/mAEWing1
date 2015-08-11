/*! \file control_functions.c
 *	\brief Shared control functions source code
 *
 *	\details Shared control specific functions
 *
 *	\ingroup control_fcns
 *
 *	\author University of Minnesota
 *	\author Aerospace Engineering and Mechanics
 *	\copyright Copyright 2011 Regents of the University of Minnesota. All rights reserved.
 *
 * $Id: control_functions.c 781 2012-03-15 16:09:37Z murch $
 */
#include <stdlib.h>
#include <math.h>

#include "../globaldefs.h"
#include AIRCRAFT_UP1DIR
#include "control_interface.h"


extern void add_trim_bias(struct control * controlData_ptr){
	// Bias controller commands with approximate trim values (set in aircraft/XXX_config.h)				
	controlData_ptr->dthr += THROTTLE_TRIM;    // throttle
	controlData_ptr->l3   += PITCH_SURF_TRIM;  // elevator
	controlData_ptr->r3   += PITCH_SURF_TRIM;  // elevator
	controlData_ptr->l2   += ROLL_SURF_TRIM;   // aileron
	controlData_ptr->r2   -= ROLL_SURF_TRIM;   // aileron
	controlData_ptr->l4   += PITCH_SURF_TRIM + ROLL_SURF_TRIM;
	controlData_ptr->r4   += PITCH_SURF_TRIM - ROLL_SURF_TRIM;
}
