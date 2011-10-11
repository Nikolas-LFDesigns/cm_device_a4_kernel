#ifndef __ACER_A4_VOL_TABLE_H
#define __ACER_A4_VOL_TABLE_H

/* different system loading cases */
enum {
	BATT_DSG_25C_10mA,
	BATT_DSG_25C_100mA,
	BATT_DSG_25C_300mA,
	BATT_DSG_25C_500mA,
	BATT_CHG_25C_500mA,
	BATT_CHG_25C_900mA
};

typedef struct {
	unsigned short	voltage;
	unsigned short	capacity;
} acer_battery_table_type;

#ifdef CONFIG_ENABLE_ONE_PERCENT_BATTERY_STEPS

/*
 * file for generation voltages is in Documentation/marcOcram
 */

#define MAX_VOLT_TABLE_SIZE 101
acer_battery_table_type acer_battery_dsg_25C_10mA_table[] = {
	{4205, 100},
	{4193, 99},
	{4181, 98},
	{4168, 97},
	{4156, 96},
	{4144, 95},
	{4134, 94},
	{4125, 93},
	{4115, 92},
	{4106, 91},
	{4096, 90},
	{4089, 89},
	{4081, 88},
	{4074, 87},
	{4066, 86},
	{4059, 85},
	{4047, 84},
	{4035, 83},
	{4022, 82},
	{4010, 81},
	{3998, 80},
	{3993, 79},
	{3987, 78},
	{3982, 77},
	{3976, 76},
	{3971, 75},
	{3965, 74},
	{3959, 73},
	{3954, 72},
	{3948, 71},
	{3942, 70},
	{3937, 69},
	{3931, 68},
	{3926, 67},
	{3920, 66},
	{3915, 65},
	{3910, 64},
	{3905, 63},
	{3899, 62},
	{3894, 61},
	{3889, 60},
	{3880, 59},
	{3871, 58},
	{3861, 57},
	{3852, 56},
	{3843, 55},
	{3838, 54},
	{3833, 53},
	{3827, 52},
	{3822, 51},
	{3817, 50},
	{3814, 49},
	{3811, 48},
	{3807, 47},
	{3804, 46},
	{3801, 45},
	{3799, 44},
	{3797, 43},
	{3794, 42},
	{3792, 41},
	{3790, 40},
	{3788, 39},
	{3787, 38},
	{3785, 37},
	{3784, 36},
	{3782, 35},
	{3781, 34},
	{3780, 33},
	{3779, 32},
	{3778, 31},
	{3777, 30},
	{3775, 29},
	{3774, 28},
	{3772, 27},
	{3771, 26},
	{3769, 25},
	{3765, 24},
	{3761, 23},
	{3758, 22},
	{3754, 21},
	{3750, 20},
	{3744, 19},
	{3737, 18},
	{3731, 17},
	{3724, 16},
	{3718, 15},
	{3713, 14},
	{3708, 13},
	{3702, 12},
	{3697, 11},
	{3692, 10},
	{3688, 9},
	{3684, 8},
	{3681, 7},
	{3677, 6},
	{3673, 5},
	{3669, 4},
	{3665, 3},
	{3662, 2},
	{3658, 1},
	{2963, 0}
};

acer_battery_table_type acer_battery_dsg_25C_100mA_table[] = {
	{4195, 100},
	{4173, 99},
	{4151, 98},
	{4129, 97},
	{4107, 96},
	{4085, 95},
	{4076, 94},
	{4067, 93},
	{4058, 92},
	{4049, 91},
	{4040, 90},
	{4032, 89},
	{4024, 88},
	{4016, 87},
	{4008, 86},
	{4000, 85},
	{3995, 84},
	{3990, 83},
	{3986, 82},
	{3981, 81},
	{3976, 80},
	{3971, 79},
	{3966, 78},
	{3960, 77},
	{3955, 76},
	{3950, 75},
	{3944, 74},
	{3938, 73},
	{3933, 72},
	{3927, 71},
	{3921, 70},
	{3915, 69},
	{3908, 68},
	{3902, 67},
	{3895, 66},
	{3889, 65},
	{3882, 64},
	{3875, 63},
	{3868, 62},
	{3861, 61},
	{3854, 60},
	{3847, 59},
	{3840, 58},
	{3833, 57},
	{3826, 56},
	{3819, 55},
	{3815, 54},
	{3812, 53},
	{3808, 52},
	{3805, 51},
	{3801, 50},
	{3798, 49},
	{3795, 48},
	{3791, 47},
	{3788, 46},
	{3785, 45},
	{3783, 44},
	{3781, 43},
	{3778, 42},
	{3776, 41},
	{3774, 40},
	{3772, 39},
	{3770, 38},
	{3768, 37},
	{3766, 36},
	{3764, 35},
	{3763, 34},
	{3762, 33},
	{3760, 32},
	{3759, 31},
	{3758, 30},
	{3756, 29},
	{3755, 28},
	{3753, 27},
	{3752, 26},
	{3750, 25},
	{3747, 24},
	{3744, 23},
	{3740, 22},
	{3737, 21},
	{3734, 20},
	{3728, 19},
	{3721, 18},
	{3715, 17},
	{3708, 16},
	{3702, 15},
	{3697, 14},
	{3692, 13},
	{3686, 12},
	{3681, 11},
	{3676, 10},
	{3672, 9},
	{3668, 8},
	{3665, 7},
	{3661, 6},
	{3657, 5},
	{3653, 4},
	{3649, 3},
	{3646, 2},
	{3642, 1},
	{3011, 0}
};

acer_battery_table_type acer_battery_dsg_25C_300mA_table[] = {
	{4201, 100},
	{4180, 99},
	{4159, 98},
	{4137, 97},
	{4116, 96},
	{4095, 95},
	{4085, 94},
	{4075, 93},
	{4065, 92},
	{4055, 91},
	{4045, 90},
	{4037, 89},
	{4029, 88},
	{4022, 87},
	{4014, 86},
	{4006, 85},
	{3994, 84},
	{3983, 83},
	{3971, 82},
	{3960, 81},
	{3948, 80},
	{3942, 79},
	{3935, 78},
	{3929, 77},
	{3922, 76},
	{3916, 75},
	{3910, 74},
	{3903, 73},
	{3897, 72},
	{3890, 71},
	{3884, 70},
	{3877, 69},
	{3870, 68},
	{3864, 67},
	{3857, 66},
	{3850, 65},
	{3844, 64},
	{3837, 63},
	{3831, 62},
	{3824, 61},
	{3818, 60},
	{3813, 59},
	{3808, 58},
	{3802, 57},
	{3797, 56},
	{3792, 55},
	{3788, 54},
	{3783, 53},
	{3779, 52},
	{3774, 51},
	{3770, 50},
	{3767, 49},
	{3764, 48},
	{3761, 47},
	{3758, 46},
	{3755, 45},
	{3752, 44},
	{3749, 43},
	{3747, 42},
	{3744, 41},
	{3741, 40},
	{3739, 39},
	{3737, 38},
	{3735, 37},
	{3733, 36},
	{3731, 35},
	{3729, 34},
	{3728, 33},
	{3726, 32},
	{3725, 31},
	{3723, 30},
	{3721, 29},
	{3719, 28},
	{3716, 27},
	{3714, 26},
	{3712, 25},
	{3709, 24},
	{3706, 23},
	{3702, 22},
	{3699, 21},
	{3696, 20},
	{3690, 19},
	{3684, 18},
	{3677, 17},
	{3671, 16},
	{3665, 15},
	{3660, 14},
	{3655, 13},
	{3651, 12},
	{3646, 11},
	{3641, 10},
	{3636, 9},
	{3631, 8},
	{3625, 7},
	{3620, 6},
	{3615, 5},
	{3610, 4},
	{3605, 3},
	{3599, 2},
	{3594, 1},
	{3025, 0}
};

acer_battery_table_type acer_battery_dsg_25C_500mA_table[] = {
	{4148, 100},
	{4132, 99},
	{4115, 98},
	{4099, 97},
	{4082, 96},
	{4066, 95},
	{4056, 94},
	{4046, 93},
	{4036, 92},
	{4026, 91},
	{4016, 90},
	{4008, 89},
	{3999, 88},
	{3991, 87},
	{3982, 86},
	{3974, 85},
	{3963, 84},
	{3952, 83},
	{3940, 82},
	{3929, 81},
	{3918, 80},
	{3910, 79},
	{3901, 78},
	{3893, 77},
	{3884, 76},
	{3876, 75},
	{3870, 74},
	{3863, 73},
	{3857, 72},
	{3850, 71},
	{3844, 70},
	{3838, 69},
	{3832, 68},
	{3825, 67},
	{3819, 66},
	{3813, 65},
	{3807, 64},
	{3801, 63},
	{3796, 62},
	{3790, 61},
	{3784, 60},
	{3779, 59},
	{3774, 58},
	{3770, 57},
	{3765, 56},
	{3760, 55},
	{3756, 54},
	{3752, 53},
	{3747, 52},
	{3743, 51},
	{3739, 50},
	{3735, 49},
	{3731, 48},
	{3728, 47},
	{3724, 46},
	{3720, 45},
	{3717, 44},
	{3714, 43},
	{3710, 42},
	{3707, 41},
	{3704, 40},
	{3702, 39},
	{3700, 38},
	{3698, 37},
	{3696, 36},
	{3694, 35},
	{3692, 34},
	{3690, 33},
	{3687, 32},
	{3685, 31},
	{3683, 30},
	{3680, 29},
	{3678, 28},
	{3675, 27},
	{3673, 26},
	{3670, 25},
	{3667, 24},
	{3664, 23},
	{3660, 22},
	{3657, 21},
	{3654, 20},
	{3648, 19},
	{3642, 18},
	{3637, 17},
	{3631, 16},
	{3625, 15},
	{3620, 14},
	{3615, 13},
	{3611, 12},
	{3606, 11},
	{3601, 10},
	{3593, 9},
	{3585, 8},
	{3578, 7},
	{3570, 6},
	{3562, 5},
	{3554, 4},
	{3546, 3},
	{3539, 2},
	{3531, 1},
	{3031, 0}
};

acer_battery_table_type acer_battery_chg_25C_500mA_table[] = {
	{4212, 100},
	{4207, 99},
	{4202, 98},
	{4198, 97},
	{4193, 96},
	{4188, 95},
	{4182, 94},
	{4176, 93},
	{4171, 92},
	{4165, 91},
	{4159, 90},
	{4155, 89},
	{4151, 88},
	{4146, 87},
	{4142, 86},
	{4138, 85},
	{4129, 84},
	{4121, 83},
	{4112, 82},
	{4104, 81},
	{4095, 80},
	{4090, 79},
	{4085, 78},
	{4079, 77},
	{4074, 76},
	{4069, 75},
	{4065, 74},
	{4062, 73},
	{4058, 72},
	{4055, 71},
	{4051, 70},
	{4046, 69},
	{4040, 68},
	{4035, 67},
	{4029, 66},
	{4024, 65},
	{4018, 64},
	{4012, 63},
	{4007, 62},
	{4001, 61},
	{3995, 60},
	{3990, 59},
	{3985, 58},
	{3979, 57},
	{3974, 56},
	{3969, 55},
	{3965, 54},
	{3961, 53},
	{3956, 52},
	{3952, 51},
	{3948, 50},
	{3944, 49},
	{3940, 48},
	{3937, 47},
	{3933, 46},
	{3929, 45},
	{3926, 44},
	{3923, 43},
	{3919, 42},
	{3916, 41},
	{3913, 40},
	{3910, 39},
	{3908, 38},
	{3905, 37},
	{3903, 36},
	{3900, 35},
	{3898, 34},
	{3896, 33},
	{3893, 32},
	{3891, 31},
	{3889, 30},
	{3887, 29},
	{3886, 28},
	{3884, 27},
	{3883, 26},
	{3881, 25},
	{3878, 24},
	{3875, 23},
	{3872, 22},
	{3869, 21},
	{3866, 20},
	{3859, 19},
	{3852, 18},
	{3845, 17},
	{3838, 16},
	{3831, 15},
	{3824, 14},
	{3817, 13},
	{3811, 12},
	{3804, 11},
	{3797, 10},
	{3793, 9},
	{3789, 8},
	{3784, 7},
	{3780, 6},
	{3776, 5},
	{3772, 4},
	{3768, 3},
	{3763, 2},
	{3759, 1},
	{3377, 0}
};

acer_battery_table_type acer_battery_chg_25C_900mA_table[] = {
	{4203, 100},
	{4200, 99},
	{4197, 98},
	{4195, 97},
	{4192, 96},
	{4189, 95},
	{4186, 94},
	{4184, 93},
	{4181, 92},
	{4179, 91},
	{4176, 90},
	{4173, 89},
	{4170, 88},
	{4166, 87},
	{4163, 86},
	{4160, 85},
	{4156, 84},
	{4152, 83},
	{4147, 82},
	{4143, 81},
	{4139, 80},
	{4137, 79},
	{4135, 78},
	{4132, 77},
	{4130, 76},
	{4128, 75},
	{4125, 74},
	{4123, 73},
	{4120, 72},
	{4118, 71},
	{4115, 70},
	{4110, 69},
	{4104, 68},
	{4099, 67},
	{4093, 66},
	{4088, 65},
	{4082, 64},
	{4076, 63},
	{4071, 62},
	{4065, 61},
	{4059, 60},
	{4054, 59},
	{4049, 58},
	{4045, 57},
	{4040, 56},
	{4035, 55},
	{4031, 54},
	{4027, 53},
	{4024, 52},
	{4020, 51},
	{4016, 50},
	{4012, 49},
	{4009, 48},
	{4005, 47},
	{4002, 46},
	{3998, 45},
	{3995, 44},
	{3992, 43},
	{3990, 42},
	{3987, 41},
	{3984, 40},
	{3981, 39},
	{3979, 38},
	{3976, 37},
	{3974, 36},
	{3971, 35},
	{3968, 34},
	{3965, 33},
	{3961, 32},
	{3958, 31},
	{3955, 30},
	{3952, 29},
	{3950, 28},
	{3947, 27},
	{3945, 26},
	{3942, 25},
	{3938, 24},
	{3934, 23},
	{3931, 22},
	{3927, 21},
	{3923, 20},
	{3917, 19},
	{3910, 18},
	{3904, 17},
	{3897, 16},
	{3891, 15},
	{3883, 14},
	{3875, 13},
	{3867, 12},
	{3859, 11},
	{3851, 10},
	{3845, 9},
	{3838, 8},
	{3832, 7},
	{3825, 6},
	{3819, 5},
	{3813, 4},
	{3806, 3},
	{3800, 2},
	{3793, 1},
	{3359, 0}
};


#else

#define MAX_VOLT_TABLE_SIZE 21
acer_battery_table_type acer_battery_dsg_25C_10mA_table[] = {
	{4205, 100},
	{4144, 95},
	{4096, 90},
	{4059, 85},
	{3998, 80},
	{3971, 75},
	{3942, 70},
	{3915, 65},
	{3889, 60},
	{3843, 55},
	{3817, 50},
	{3801, 45},
	{3790, 40},
	{3782, 35},
	{3777, 30},
	{3769, 25},
	{3750, 20},
	{3718, 15},
	{3692, 10},
	{3673, 5},
	{2963, 0}
};

acer_battery_table_type acer_battery_dsg_25C_100mA_table[] = {
	{4195, 100},
	{4085, 95},
	{4040, 90},
	{4000, 85},
	{3976, 80},
	{3950, 75},
	{3921, 70},
	{3889, 65},
	{3854, 60},
	{3819, 55},
	{3801, 50},
	{3785, 45},
	{3774, 40},
	{3764, 35},
	{3758, 30},
	{3750, 25},
	{3734, 20},
	{3702, 15},
	{3676, 10},
	{3657, 5},
	{3011, 0}
};

acer_battery_table_type acer_battery_dsg_25C_300mA_table[] = {
	{4201, 100},
	{4095, 95},
	{4045, 90},
	{4006, 85},
	{3948, 80},
	{3916, 75},
	{3884, 70},
	{3850, 65},
	{3818, 60},
	{3792, 55},
	{3770, 50},
	{3755, 45},
	{3741, 40},
	{3731, 35},
	{3723, 30},
	{3712, 25},
	{3696, 20},
	{3665, 15},
	{3641, 10},
	{3615, 5},
	{3025, 0}
};

acer_battery_table_type acer_battery_dsg_25C_500mA_table[] = {
	{4148, 100},
	{4066, 95},
	{4016, 90},
	{3974, 85},
	{3918, 80},
	{3876, 75},
	{3844, 70},
	{3813, 65},
	{3784, 60},
	{3760, 55},
	{3739, 50},
	{3720, 45},
	{3704, 40},
	{3694, 35},
	{3683, 30},
	{3670, 25},
	{3654, 20},
	{3625, 15},
	{3601, 10},
	{3562, 5},
	{3031, 0}
};

acer_battery_table_type acer_battery_chg_25C_500mA_table[] = {
	{4212, 100},
	{4188, 95},
	{4159, 90},
	{4138, 85},
	{4095, 80},
	{4069, 75},
	{4051, 70},
	{4024, 65},
	{3995, 60},
	{3969, 55},
	{3948, 50},
	{3929, 45},
	{3913, 40},
	{3900, 35},
	{3889, 30},
	{3881, 25},
	{3866, 20},
	{3831, 15},
	{3797, 10},
	{3776, 5},
	{3377, 0}
};

acer_battery_table_type acer_battery_chg_25C_900mA_table[] = {
	{4203, 100},
	{4189, 95},
	{4176, 90},
	{4160, 85},
	{4139, 80},
	{4128, 75},
	{4115, 70},
	{4088, 65},
	{4059, 60},
	{4035, 55},
	{4016, 50},
	{3998, 45},
	{3984, 40},
	{3971, 35},
	{3955, 30},
	{3942, 25},
	{3923, 20},
	{3891, 15},
	{3851, 10},
	{3819, 5},
	{3359, 0}
};

#endif // CONFIG_ENABLE_ONE_PERCENT_BATTERY_STEPS

#endif //__ACER_A4_VOL_TABLE_H
