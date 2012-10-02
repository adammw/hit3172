/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Resources
*
* Wrapping sgResources.pas
*/

#include "SGSDK.h"
#include "Resources.h"

#include "Types.h"

void app_path(char *result)
{
    sg_Resources_AppPath(result);
}

void filename_to_resource(const char *name, resource_kind kind, char *result)
{
    sg_Resources_FilenameToResource(name, kind, result);
}

bool has_resource_bundle(const char *name)
{
    return sg_Resources_HasResourceBundle(name) != 0;
}

#ifdef __cplusplus

void load_resource_bundle(const char *name)
{
    sg_Resources_LoadResourceBundle(name, true != 0);
}

#endif

void load_resource_bundle_with_progress(const char *name)
{
    sg_Resources_LoadResourceBundle(name, true != 0);
}

void load_resource_bundle(const char *name, bool showProgress)
{
    sg_Resources_LoadResourceBundle(name, showProgress != 0);
}

void load_resource_bundle_named(const char *name, const char *filename, bool showProgress)
{
    sg_Resources_LoadResourceBundleNamed(name, filename, showProgress != 0);
}

#ifdef __cplusplus

void path_to_resource(const char *filename, char *result)
{
    sg_Resources_PathToOtherResource(filename, result);
}

#endif

void path_to_other_resource(const char *filename, char *result)
{
    sg_Resources_PathToOtherResource(filename, result);
}

void path_to_resource(const char *filename, resource_kind kind, char *result)
{
    sg_Resources_PathToResource(filename, kind, result);
}

#ifdef __cplusplus

void path_to_resource(const char *filename, const char *subdir, char *result)
{
    sg_Resources_PathToResourseInSubdir(filename, subdir, result);
}

#endif

void path_to_resourse_in_subdir(const char *filename, const char *subdir, char *result)
{
    sg_Resources_PathToResourseInSubdir(filename, subdir, result);
}

#ifdef __cplusplus

void path_to_resource(const char *filename, resource_kind kind, const string_array subPaths, char *result, int32_t subPaths_len)
{
    sg_Resources_PathToResourceWithSubPaths(filename, kind, subPaths, result, subPaths_len);
}

#endif

void path_to_resource_with_sub_paths(const char *filename, resource_kind kind, const string_array subPaths, char *result, int32_t subPaths_len)
{
    sg_Resources_PathToResourceWithSubPaths(filename, kind, subPaths, result, subPaths_len);
}

#ifdef __cplusplus

void path_to_resource(const char *filename, resource_kind kind, const char *subdir, char *result)
{
    sg_Resources_PathToResourseKindInSubdir(filename, kind, subdir, result);
}

#endif

void path_to_resourse_kind_in_subdir(const char *filename, resource_kind kind, const char *subdir, char *result)
{
    sg_Resources_PathToResourseKindInSubdir(filename, kind, subdir, result);
}

#ifdef __cplusplus

void path_to_resource_with_base(const char *path, const char *filename, char *result)
{
    sg_Resources_PathToOtherResourceWithBase(path, filename, result);
}

#endif

void path_to_other_resource_with_base(const char *path, const char *filename, char *result)
{
    sg_Resources_PathToOtherResourceWithBase(path, filename, result);
}

void path_to_resource_with_base(const char *path, const char *filename, resource_kind kind, char *result)
{
    sg_Resources_PathToResourceWithBase(path, filename, kind, result);
}

void register_free_notifier(free_notifier  fn)
{
    sg_Resources_RegisterFreeNotifier(fn);
}

void release_all_resources()
{
    sg_Resources_ReleaseAllResources();
}

void release_resource_bundle(const char *name)
{
    sg_Resources_ReleaseResourceBundle(name);
}

void set_app_path(const char *path)
{
    sg_Resources_SetAppPath(path);
}

#ifdef __cplusplus

void set_app_path(const char *path, bool withExe)
{
    sg_Resources_SetAppPathWithExe(path, withExe != 0);
}

#endif

void set_app_path_with_exe(const char *path, bool withExe)
{
    sg_Resources_SetAppPathWithExe(path, withExe != 0);
}

void show_logos()
{
    sg_Resources_ShowLogos();
}
