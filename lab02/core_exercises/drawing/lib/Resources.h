/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Resources
*
* Wrapping sgResources.pas
*/

#ifndef sgResources
#define sgResources

#include <stdbool.h>
#include <stdint.h>

#include "Types.h"

void app_path(char *result);
void filename_to_resource(const char *name, resource_kind kind, char *result);
bool has_resource_bundle(const char *name);
void load_resource_bundle_with_progress(const char *name);
void load_resource_bundle(const char *name, bool showProgress);
void load_resource_bundle_named(const char *name, const char *filename, bool showProgress);
void path_to_other_resource(const char *filename, char *result);
void path_to_resource(const char *filename, resource_kind kind, char *result);
void path_to_resourse_in_subdir(const char *filename, const char *subdir, char *result);
void path_to_resource_with_sub_paths(const char *filename, resource_kind kind, const string_array subPaths, char *result, int32_t subPaths_len);
void path_to_resourse_kind_in_subdir(const char *filename, resource_kind kind, const char *subdir, char *result);
void path_to_other_resource_with_base(const char *path, const char *filename, char *result);
void path_to_resource_with_base(const char *path, const char *filename, resource_kind kind, char *result);
void register_free_notifier(free_notifier  fn);
void release_all_resources();
void release_resource_bundle(const char *name);
void set_app_path(const char *path);
void set_app_path_with_exe(const char *path, bool withExe);
void show_logos();

#ifdef __cplusplus
// C++ overloaded functions
void load_resource_bundle(const char *name);
void path_to_resource(const char *filename, char *result);
void path_to_resource(const char *filename, const char *subdir, char *result);
void path_to_resource(const char *filename, resource_kind kind, const string_array subPaths, char *result, int32_t subPaths_len);
void path_to_resource(const char *filename, resource_kind kind, const char *subdir, char *result);
void path_to_resource_with_base(const char *path, const char *filename, char *result);
void set_app_path(const char *path, bool withExe);

#endif

#endif

