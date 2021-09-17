#ifdef DLL3_EXPORTS
#define DLL3_API __declspec(dllexport)
#else
#define DLL3_API __declspec(dllimport)
#endif
/**
        @file interface.h
        @brief C interface header (for python notably)
        @author Alban Siffer
        @date 03 March 2018
*/

#include "dspot.h"

using namespace std;

extern "C" {
// ----------------------------------------------------------------------------
// SPOT
// ----------------------------------------------------------------------------
DLL3_API Spot* Spot_new(double q,
    int n_init,
    double level,
    bool up,
    bool down,
    bool alert,
    bool bounded,
    int max_excess);

DLL3_API void Spot_delete(Spot *s);

DLL3_API int Spot_step(Spot* s, double x);

DLL3_API SpotStatus Spot_status(Spot* s);

DLL3_API SpotConfig Spot_config(Spot* s);

DLL3_API double Spot_getUpperThreshold(Spot* s);

DLL3_API double Spot_getLowerThreshold(Spot* s);

DLL3_API double Spot_getUpper_t(Spot* s);

DLL3_API double Spot_getLower_t(Spot* s);

DLL3_API void Spot_set_q(Spot* s, double q_new);

DLL3_API double Spot_up_probability(Spot* s, double z);

DLL3_API double Spot_down_probability(Spot* s, double z);



// ----------------------------------------------------------------------------
// DSPOT
// ----------------------------------------------------------------------------

// "lightweight" constructor (to pass lower than 256 bytes)
DLL3_API DSpot* DSpot_new_light( int d,
                        int n_init,
                        double level,
                        bool up,
                        bool down,
                        bool alert,
                        bool bounded,
                        int max_excess);
/*
DSpot* DSpot_new(int d,
                 double q,
                 int n_init,
                 double level,
                 bool up,
                 bool down,
                 bool alert,
                 bool bounded,
                 int max_excess);*/


DLL3_API void DSpot_delete(DSpot* ds);

DLL3_API DSpotStatus DSpot_status(DSpot* ds);

DLL3_API DSpotConfig DSpot_config(DSpot* ds);

DLL3_API int DSpot_step(DSpot* ds, double x);

DLL3_API double DSpot_getUpperThreshold(DSpot* ds);

DLL3_API double DSpot_getLowerThreshold(DSpot* ds);

DLL3_API double DSpot_getUpper_t(DSpot* ds);

DLL3_API double DSpot_getLower_t(DSpot* ds);

DLL3_API double DSpot_getDrift(DSpot* ds);

DLL3_API void DSpot_set_q(DSpot* ds, double q_new);

DLL3_API double DSpot_up_probability(DSpot* ds, double z);

DLL3_API double DSpot_down_probability(DSpot* ds, double z);



// ----------------------------------------------------------------------------
// SPOT STATUS
// ----------------------------------------------------------------------------
DLL3_API SpotStatus* Spot_status_ptr(Spot* s);

DLL3_API void Spot_status_delete(SpotStatus* ss);

// ----------------------------------------------------------------------------
// DSPOT STATUS
// ----------------------------------------------------------------------------
DLL3_API DSpotStatus* DSpot_status_ptr(DSpot* ds);

DLL3_API void DSpot_status_delete(DSpotStatus* ds);


// ----------------------------------------------------------------------------
// SPOT/DSPOT status methods
// ----------------------------------------------------------------------------
DLL3_API int _status_get_n(SpotStatus* ss);

DLL3_API int _status_get_ex_up(SpotStatus* ss);

DLL3_API int _status_get_ex_down(SpotStatus* ss);

DLL3_API int _status_get_Nt_up(SpotStatus* ss);

DLL3_API int _status_get_Nt_down(SpotStatus* ss);

DLL3_API int _status_get_al_up(SpotStatus* ss);

DLL3_API int _status_get_al_down(SpotStatus* ss);

DLL3_API double _status_get_t_up(SpotStatus* ss);

DLL3_API double _status_get_t_down(SpotStatus* ss);

DLL3_API double _status_get_z_up(SpotStatus* ss);

DLL3_API double _status_get_z_down(SpotStatus* ss);

// specific to DSpot
DLL3_API double _status_get_drift(DSpotStatus* dss);

// ----------------------------------------------------------------------------
// SPOT CONFIG
// ----------------------------------------------------------------------------
DLL3_API SpotConfig* Spot_config_ptr(Spot* s);

DLL3_API void Spot_config_delete(SpotConfig* sc);

// ----------------------------------------------------------------------------
// DSPOT CONFIG
// ----------------------------------------------------------------------------
DLL3_API DSpotConfig* DSpot_config_ptr(DSpot* ds);

DLL3_API void DSpot_config_delete(DSpotConfig* dsc);


// ----------------------------------------------------------------------------
// SPOT/DSPOT config methods
// ----------------------------------------------------------------------------

DLL3_API double _config_get_q(SpotConfig* sc);

DLL3_API int _config_get_bounded(SpotConfig* sc);

DLL3_API int _config_get_max_excess(SpotConfig* sc);

DLL3_API int _config_get_alert(SpotConfig* sc);

DLL3_API int _config_get_up(SpotConfig* sc);

DLL3_API int _config_get_down(SpotConfig* sc);

DLL3_API int _config_get_n_init(SpotConfig* sc);

DLL3_API double _config_get_level(SpotConfig* sc);

// specific to DSpot
DLL3_API double _config_get_depth(DSpotConfig* dsc);


}

