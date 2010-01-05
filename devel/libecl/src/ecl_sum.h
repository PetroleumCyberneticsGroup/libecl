#ifndef __ECL_SUM_H__
#define __ECL_SUM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stringlist.h>
#include <ecl_smspec.h>
#include <time_t_vector.h>
#include <stringlist.h>

typedef struct ecl_sum_struct       ecl_sum_type;


void             ecl_sum_summarize( const ecl_sum_type * ecl_sum , FILE * stream );
bool             ecl_sum_general_is_total(const ecl_sum_type * ecl_sum , const char * gen_key);
bool             ecl_sum_var_is_total(const ecl_sum_type * ecl_sum , const char * gen_key);
void             ecl_sum_fread_realloc_data(ecl_sum_type *, const stringlist_type * data_files);
void             ecl_sum_free_data(ecl_sum_type * );
void             ecl_sum_free__(void * );
void             ecl_sum_free(ecl_sum_type * );
ecl_sum_type   * ecl_sum_fread_alloc(const char * , const stringlist_type * data_files, const char * key_join_string);
ecl_sum_type   * ecl_sum_fread_alloc_case(const char *  , const char * key_join_string);

/* Accessor functions : */
double            ecl_sum_get_well_var(const ecl_sum_type * ecl_sum , int ministep , const char * well , const char *var);
int               ecl_sum_get_well_var_index(const ecl_sum_type * ecl_sum , const char * well , const char *var);
bool              ecl_sum_has_well_var(const ecl_sum_type * ecl_sum , const char * well , const char *var);
double            ecl_sum_get_well_var_from_sim_days( const ecl_sum_type * ecl_sum , double sim_days , const char * well , const char * var);
double            ecl_sum_get_well_var_from_sim_time( const ecl_sum_type * ecl_sum , time_t sim_time , const char * well , const char * var);

double            ecl_sum_get_group_var(const ecl_sum_type * ecl_sum , int ministep , const char * group , const char *var);
int               ecl_sum_get_group_var_index(const ecl_sum_type * ecl_sum , const char * group , const char *var);
bool              ecl_sum_has_group_var(const ecl_sum_type * ecl_sum , const char * group , const char *var);

double            ecl_sum_get_field_var(const ecl_sum_type * ecl_sum , int ministep , const char *var);
int               ecl_sum_get_field_var_index(const ecl_sum_type * ecl_sum , const char *var);
bool              ecl_sum_has_field_var(const ecl_sum_type * ecl_sum , const char *var);
double            ecl_sum_get_field_var_from_sim_days( const ecl_sum_type * ecl_sum , double sim_days , const char * var);
double            ecl_sum_get_field_var_from_sim_time( const ecl_sum_type * ecl_sum , time_t sim_time , const char * var);

double            ecl_sum_get_block_var(const ecl_sum_type * ecl_sum , int ministep , const char * block_var , int block_nr);
int               ecl_sum_get_block_var_index(const ecl_sum_type * ecl_sum , const char * block_var , int block_nr);
bool              ecl_sum_has_block_var(const ecl_sum_type * ecl_sum , const char * block_var , int block_nr);
double            ecl_sum_get_block_var_ijk(const ecl_sum_type * ecl_sum , int ministep , const char * block_var , int i , int j , int k);
int               ecl_sum_get_block_var_index_ijk(const ecl_sum_type * ecl_sum , const char * block_var , int i , int j , int k);
bool              ecl_sum_has_block_var_ijk(const ecl_sum_type * ecl_sum , const char * block_var , int i , int j , int k);

double            ecl_sum_get_region_var(const ecl_sum_type * ecl_sum , int ministep , int region_nr , const char *var);
int               ecl_sum_get_region_var_index(const ecl_sum_type * ecl_sum , int region_nr , const char *var);
bool              ecl_sum_has_region_var(const ecl_sum_type * ecl_sum , int region_nr , const char *var);

double            ecl_sum_get_misc_var(const ecl_sum_type * ecl_sum , int ministep , const char *var);
int               ecl_sum_get_misc_var_index(const ecl_sum_type * ecl_sum , const char *var);
bool              ecl_sum_has_misc_var(const ecl_sum_type * ecl_sum , const char *var);

double            ecl_sum_get_well_completion_var(const ecl_sum_type * ecl_sum , int ministep , const char * well , const char *var, int cell_nr);
int               ecl_sum_get_well_completion_var_index(const ecl_sum_type * ecl_sum , const char * well , const char *var, int cell_nr);
bool              ecl_sum_has_well_completion_var(const ecl_sum_type * ecl_sum , const char * well , const char *var, int cell_nr);
  
double            ecl_sum_get_general_var(const ecl_sum_type * ecl_sum , int ministep , const char * lookup_kw);
int               ecl_sum_get_general_var_index(const ecl_sum_type * ecl_sum , const char * lookup_kw);
bool              ecl_sum_has_general_var(const ecl_sum_type * ecl_sum , const char * lookup_kw);
double            ecl_sum_get_general_var_from_sim_days( const ecl_sum_type * ecl_sum , double sim_days , const char * var);
double            ecl_sum_get_general_var_from_sim_time( const ecl_sum_type * ecl_sum , time_t sim_time , const char * var);
const char *      ecl_sum_get_general_var_unit( const ecl_sum_type * ecl_sum , const char * var);
/***************/
void              ecl_sum_fprintf(const ecl_sum_type * , FILE * , int , const char **  , bool report_only);




/* Time related functions */
int    ecl_sum_get_first_ministep_gt(const ecl_sum_type * ecl_sum , int smspec_index , double limit);
int    ecl_sum_get_last_ministep(const ecl_sum_type * ecl_sum );
int    ecl_sum_get_first_ministep(const ecl_sum_type * ecl_sum );
int    ecl_sum_get_last_report_step( const ecl_sum_type * ecl_sum );
int    ecl_sum_get_first_report_step( const ecl_sum_type * ecl_sum );
int    ecl_sum_get_report_ministep_end( const ecl_sum_type * ecl_sum, int report_step);
int    ecl_sum_get_report_ministep_start( const ecl_sum_type * ecl_sum, int report_step);
bool   ecl_sum_has_report_step(const ecl_sum_type * ecl_sum , int report_step );
bool   ecl_sum_has_ministep(const ecl_sum_type * ecl_sum , int ministep );
void   ecl_sum_get_ministep_range(const ecl_sum_type * ecl_sum , int * ministep1, int * ministep2);
void   ecl_sum_report2ministep_range(const ecl_sum_type * ecl_sum , int report_step , int * ministep1 , int * ministep2 );
time_t ecl_sum_get_sim_time( const ecl_sum_type * ecl_sum , int ministep );
time_t ecl_sum_get_report_time( const ecl_sum_type * ecl_sum , int report_step );
double ecl_sum_get_sim_days( const ecl_sum_type * ecl_sum , int ministep );

time_t_vector_type * ecl_sum_alloc_time_vector( const ecl_sum_type * ecl_sum  , bool report_only);
time_t       ecl_sum_get_end_time( const ecl_sum_type * ecl_sum);
int          ecl_sum_get_ministep_from_sim_days( const ecl_sum_type * ecl_sum , double sim_days);
int          ecl_sum_get_ministep_from_sim_time( const ecl_sum_type * ecl_sum , time_t sim_time);
time_t       ecl_sum_get_start_time(const ecl_sum_type * );
const char * ecl_sum_get_case(const ecl_sum_type * );

/*****************************************************************/
stringlist_type     * ecl_sum_alloc_well_list( const ecl_sum_type * ecl_sum );
stringlist_type     * ecl_sum_alloc_well_var_list( const ecl_sum_type * ecl_sum );
stringlist_type     * ecl_sum_alloc_matching_general_var_list(const ecl_sum_type * ecl_sum , const char * pattern);  
ecl_smspec_var_type   ecl_sum_identify_var_type(const ecl_sum_type * ecl_sum , const char * var);

#ifdef __cplusplus
}
#endif
#endif
