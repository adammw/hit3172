/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Graphics
*
* Wrapping sgGraphics.pas
*/

#ifndef sgGraphics
#define sgGraphics

#include <stdbool.h>
#include <stdint.h>

#include "Types.h"

unsigned char blue_of(color c);
float brightness_of(color c);
void change_screen_size(int32_t width, int32_t height);
void clear_screen();
void clear_screen_to(color toColor);
void color_components(color c, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a);
color color_from_bitmap(bitmap bmp, color apiColor);
void color_to_string(color c, char *result);
rectangle current_screen_clip();
rectangle current_bmp_clip(bitmap bmp);
void draw_circle(color clr, float xc, float yc, int32_t radius);
void draw_circle_at_point(color clr, const point2d *position, int32_t radius);
void draw_circle_at_point_byval(color clr, const point2d position, int32_t radius);
void draw_or_fill_circle_at_point(color clr, bool filled, const point2d *position, int32_t radius);
void draw_or_fill_circle_at_point_byval(color clr, bool filled, const point2d position, int32_t radius);
void draw_circle_struct(color clr, const circle *c);
void draw_circle_struct_byval(color clr, const circle c);
void draw_circle_struct_onto(bitmap dest, color clr, const circle *c);
void draw_circle_struct_onto_byval(bitmap dest, color clr, const circle c);
void draw_or_fill_circle_struct(color clr, bool filled, const circle *c);
void draw_or_fill_circle_struct_byval(color clr, bool filled, const circle c);
void draw_or_fill_circle_struct_onto(bitmap dest, color clr, bool filled, const circle *c);
void draw_or_fill_circle_struct_onto_byval(bitmap dest, color clr, bool filled, const circle c);
void draw_circle_at_point_onto(bitmap dest, color clr, const point2d *point, int32_t radius);
void draw_circle_at_point_onto_byval(bitmap dest, color clr, const point2d point, int32_t radius);
void draw_circle_onto(bitmap dest, color clr, float xc, float yc, int32_t radius);
void draw_or_fill_circle_at_point_onto(bitmap dest, color clr, bool filled, const point2d *point, int32_t radius);
void draw_or_fill_circle_at_point_onto_byval(bitmap dest, color clr, bool filled, const point2d point, int32_t radius);
void draw_or_fill_circle(color clr, bool filled, float xc, float yc, int32_t radius);
void draw_or_fill_circle_onto(bitmap dest, color clr, bool filled, float xc, float yc, int32_t radius);
void draw_circle_struct_on_screen(color clr, const circle *c);
void draw_circle_struct_on_screen_byval(color clr, const circle c);
void draw_or_fill_circle_struct_on_screen(color clr, bool filled, const circle *c);
void draw_or_fill_circle_struct_on_screen_byval(color clr, bool filled, const circle c);
void draw_circle_at_point_on_screen(color clr, const point2d *position, int32_t radius);
void draw_circle_at_point_on_screen_byval(color clr, const point2d position, int32_t radius);
void draw_circle_on_screen(color clr, float xc, float yc, int32_t radius);
void draw_or_fill_circle_at_point_on_screen(color clr, bool filled, const point2d *position, int32_t radius);
void draw_or_fill_circle_at_point_on_screen_byval(color clr, bool filled, const point2d position, int32_t radius);
void draw_or_fill_circle_on_screen(color clr, bool filled, float xc, float yc, int32_t radius);
void draw_ellipse_in_rect(color clr, const rectangle *source);
void draw_ellipse_in_rect_byval(color clr, const rectangle source);
void draw_or_fill_ellipse_in_rect(color clr, bool filled, const rectangle *source);
void draw_or_fill_ellipse_in_rect_byval(color clr, bool filled, const rectangle source);
void draw_ellipse_in_rect_onto(bitmap dest, color clr, const rectangle *source);
void draw_ellipse_in_rect_onto_byval(bitmap dest, color clr, const rectangle source);
void draw_or_fill_ellipse_in_rect_onto(bitmap dest, color clr, bool filled, const rectangle *source);
void draw_or_fill_ellipse_in_rect_onto_byval(bitmap dest, color clr, bool filled, const rectangle source);
void draw_ellipse(color clr, float xPos, float yPos, int32_t width, int32_t height);
void draw_ellipse_onto(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_or_fill_ellipse(color clr, bool filled, float xPos, float yPos, int32_t width, int32_t height);
void draw_or_fill_ellipse_onto(bitmap dest, color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_ellipse_in_rect_on_screen(color clr, const rectangle *source);
void draw_ellipse_in_rect_on_screen_byval(color clr, const rectangle source);
void draw_or_fill_ellipse_in_rect_on_screen(color clr, bool filled, const rectangle *source);
void draw_or_fill_ellipse_in_rect_on_screen_byval(color clr, bool filled, const rectangle source);
void draw_ellipse_on_screen(color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_or_fill_ellipse_on_screen(color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_horizontal_line(color clr, float y, float x1, float x2);
void draw_horizontal_line_onto(bitmap dest, color clr, int32_t y, int32_t x1, int32_t x2);
void draw_horizontal_line_on_screen(color clr, int32_t y, int32_t x1, int32_t x2);
void draw_line_segment(color clr, const line_segment *line);
void draw_line_segment_byval(color clr, const line_segment line);
void draw_line_pts(color clr, const point2d *startPt, const point2d *endPt);
void draw_line_pts_byval(color clr, const point2d startPt, const point2d endPt);
void draw_line_segment_onto(bitmap dest, color clr, const line_segment *line);
void draw_line_segment_onto_byval(bitmap dest, color clr, const line_segment line);
void draw_line_pts_onto(bitmap dest, color clr, const point2d *startPt, const point2d *endPt);
void draw_line_pts_onto_byval(bitmap dest, color clr, const point2d startPt, const point2d endPt);
void draw_line(color clr, float xPosStart, float yPosStart, float xPosEnd, float yPosEnd);
void draw_line_onto(bitmap dest, color clr, int32_t xPosStart, int32_t yPosStart, int32_t xPosEnd, int32_t yPosEnd);
void draw_line_segment_on_screen(color clr, const line_segment *line);
void draw_line_segment_on_screen_byval(color clr, const line_segment line);
void draw_line_pts_on_screen(color clr, const point2d *startPt, const point2d *endPt);
void draw_line_pts_on_screen_byval(color clr, const point2d startPt, const point2d endPt);
void draw_line_on_screen(color clr, int32_t xPosStart, int32_t yPosStart, int32_t xPosEnd, int32_t yPosEnd);
void draw_line_segments(color clr, const lines_array lines, int32_t lines_len);
void draw_pixel_at_point(color clr, const point2d *position);
void draw_pixel_at_point_byval(color clr, const point2d position);
void draw_pixel(color clr, float x, float y);
void draw_pixel_at_point_onto(bitmap dest, color clr, const point2d *position);
void draw_pixel_at_point_onto_byval(bitmap dest, color clr, const point2d position);
void draw_pixel_onto(bitmap dest, color clr, int32_t x, int32_t y);
void draw_pixel_at_point_on_screen(color clr, const point2d *position);
void draw_pixel_at_point_on_screen_byval(color clr, const point2d position);
void draw_pixel_on_screen(color clr, int32_t x, int32_t y);
void draw_rectangle(color clr, float xPos, float yPos, int32_t width, int32_t height);
void draw_rectangle_struct(color clr, const rectangle *source);
void draw_rectangle_struct_byval(color clr, const rectangle source);
void draw_or_fill_rectangle_struct(color clr, bool filled, const rectangle *source);
void draw_or_fill_rectangle_struct_byval(color clr, bool filled, const rectangle source);
void draw_rectangle_struct_onto(bitmap dest, color clr, const rectangle *source);
void draw_rectangle_struct_onto_byval(bitmap dest, color clr, const rectangle source);
void draw_or_fill_rectangle_struct_onto(bitmap dest, color clr, bool filled, const rectangle *source);
void draw_or_fill_rectangle_struct_onto_byval(bitmap dest, color clr, bool filled, const rectangle source);
void draw_or_fill_rectangle(color clr, bool filled, float xPos, float yPos, int32_t width, int32_t height);
void draw_rectangle_onto(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_or_fill_rectangle_onto(bitmap dest, color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_rectangle_struct_on_screen(color clr, const rectangle *source);
void draw_rectangle_struct_on_screen_byval(color clr, const rectangle source);
void draw_or_fill_rectangle_struct_on_screen(color clr, bool filled, const rectangle *source);
void draw_or_fill_rectangle_struct_on_screen_byval(color clr, bool filled, const rectangle source);
void draw_rectangle_on_screen(color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_or_fill_rectangle_on_screen(color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_triangle(color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void draw_triangle_struct(color clr, const triangle  *tri);
void draw_triangle_struct_byval(color clr, const triangle  tri);
void draw_or_fill_triangle_struct(color clr, bool filled, const triangle  *tri);
void draw_or_fill_triangle_struct_byval(color clr, bool filled, const triangle  tri);
void draw_triangle_struct_onto(bitmap dest, color clr, const triangle  *tri);
void draw_triangle_struct_onto_byval(bitmap dest, color clr, const triangle  tri);
void draw_or_fill_triangle_struct_onto(bitmap dest, color clr, bool filled, const triangle  *tri);
void draw_or_fill_triangle_struct_onto_byval(bitmap dest, color clr, bool filled, const triangle  tri);
void draw_triangle_onto(bitmap dest, color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void draw_triangle_struct_on_screen(color clr, const triangle  *tri);
void draw_triangle_struct_on_screen_byval(color clr, const triangle  tri);
void draw_or_fill_triangle_struct_on_screen(color clr, bool filled, const triangle  *tri);
void draw_or_fill_triangle_struct_on_screen_byval(color clr, bool filled, const triangle  tri);
void draw_triangle_on_screen(color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void draw_vertical_line(color clr, float x, float y1, float y2);
void draw_vertical_line_onto(bitmap dest, color clr, int32_t x, int32_t y1, int32_t y2);
void draw_vertical_line_on_screen(color clr, int32_t x, int32_t y1, int32_t y2);
void fill_circle(color clr, float xc, float yc, int32_t radius);
void fill_circle_at_point(color clr, const point2d *position, int32_t radius);
void fill_circle_at_point_byval(color clr, const point2d position, int32_t radius);
void fill_circle_struct(color clr, const circle *c);
void fill_circle_struct_byval(color clr, const circle c);
void fill_circle_struct_onto(bitmap dest, color clr, const circle *c);
void fill_circle_struct_onto_byval(bitmap dest, color clr, const circle c);
void fill_circle_at_point_onto(bitmap dest, color clr, const point2d *point, int32_t radius);
void fill_circle_at_point_onto_byval(bitmap dest, color clr, const point2d point, int32_t radius);
void fill_circle_onto(bitmap dest, color clr, float xc, float yc, int32_t radius);
void fill_circle_struct_on_screen(color clr, const circle *c);
void fill_circle_struct_on_screen_byval(color clr, const circle c);
void fill_circle_at_point_on_screen(color clr, const point2d *position, int32_t radius);
void fill_circle_at_point_on_screen_byval(color clr, const point2d position, int32_t radius);
void fill_circle_on_screen(color clr, float xc, float yc, int32_t radius);
void fill_ellipse_in_rect(color clr, const rectangle *source);
void fill_ellipse_in_rect_byval(color clr, const rectangle source);
void fill_ellipse_in_rect_onto(bitmap dest, color clr, const rectangle *source);
void fill_ellipse_in_rect_onto_byval(bitmap dest, color clr, const rectangle source);
void fill_ellipse(color clr, float xPos, float yPos, int32_t width, int32_t height);
void fill_ellipse_onto(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_ellipse_in_rect_on_screen(color clr, const rectangle *source);
void fill_ellipse_in_rect_on_screen_byval(color clr, const rectangle source);
void fill_ellipse_on_screen(color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_rectangle(color clr, float xPos, float yPos, int32_t width, int32_t height);
void fill_rectangle_struct(color clr, const rectangle *source);
void fill_rectangle_struct_byval(color clr, const rectangle source);
void fill_rectangle_struct_onto(bitmap dest, color clr, const rectangle *source);
void fill_rectangle_struct_onto_byval(bitmap dest, color clr, const rectangle source);
void fill_rectangle_onto(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_rectangle_struct_on_screen(color clr, const rectangle *source);
void fill_rectangle_struct_on_screen_byval(color clr, const rectangle source);
void fill_rectangle_on_screen(color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_triangle(color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void fill_triangle_struct(color clr, const triangle  *tri);
void fill_triangle_struct_byval(color clr, const triangle  tri);
void fill_triangle_struct_onto(bitmap dest, color clr, const triangle  *tri);
void fill_triangle_struct_onto_byval(bitmap dest, color clr, const triangle  tri);
void fill_triangle_onto(bitmap dest, color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void fill_triangle_struct_on_screen(color clr, const triangle  *tri);
void fill_triangle_struct_on_screen_byval(color clr, const triangle  tri);
void fill_triangle_on_screen(color clr, float x1, float y1, float x2, float y2, float x3, float y3);
color get_pixel(bitmap bmp, int32_t x, int32_t y);
color get_pixel_from_screen(int32_t x, int32_t y);
unsigned char green_of(color c);
color hsbcolor(float hue, float saturation, float brightness);
void hsbvalues_of(color c, float *h, float *s, float *b);
float hue_of(color c);
void open_graphics_window800x600(const char *caption);
void open_graphics_window(const char *caption, int32_t width, int32_t height);
void pop_clip_screen();
void pop_clip_bmp(bitmap bmp);
void push_clip_rect(const rectangle *r);
void push_clip_rect_byval(const rectangle r);
void push_clip_rect_for_bitmap(bitmap bmp, const rectangle *r);
void push_clip_rect_for_bitmap_byval(bitmap bmp, const rectangle r);
void push_clip_xy(int32_t x, int32_t y, int32_t w, int32_t h);
void put_pixel(bitmap bmp, color value, int32_t x, int32_t y);
color rgbacolor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
color rgbafloat_color(float r, float g, float b, float a);
color rgbcolor(unsigned char red, unsigned char green, unsigned char blue);
color rgbfloat_color(float r, float g, float b);
color random_color();
color random_rgbcolor(unsigned char alpha);
unsigned char red_of(color c);
void refresh_screen();
void refresh_screen_restrict_fps(uint32_t TargetFPS);
void reset_clip();
void reset_clip_for_bitmap(bitmap bmp);
float saturation_of(color c);
int32_t screen_height();
int32_t screen_width();
void set_clip(const rectangle *r);
void set_clip_byval(const rectangle r);
void set_bmp_clip(bitmap bmp, const rectangle *r);
void set_bmp_clip_byval(bitmap bmp, const rectangle r);
void set_clip_xy(int32_t x, int32_t y, int32_t w, int32_t h);
void set_bmp_clip_xy(bitmap bmp, int32_t x, int32_t y, int32_t w, int32_t h);
void set_icon(const char *filename);
void take_screenshot(const char *basename);
void toggle_full_screen();
void toggle_window_border();
unsigned char transparency_of(color c);

#ifdef __cplusplus
// C++ overloaded functions
void clear_screen(color toColor);
void color_components(color c, unsigned char &r, unsigned char &g, unsigned char &b, unsigned char &a);
color color_from(bitmap bmp, color apiColor);
rectangle current_clip();
rectangle current_clip(bitmap bmp);
void draw_circle(color clr, const point2d &position, int32_t radius);
void draw_circle(color clr, bool filled, const point2d &position, int32_t radius);
void draw_circle(color clr, const circle &c);
void draw_circle(bitmap dest, color clr, const circle &c);
void draw_circle(color clr, bool filled, const circle &c);
void draw_circle(bitmap dest, color clr, bool filled, const circle &c);
void draw_circle(bitmap dest, color clr, const point2d &point, int32_t radius);
void draw_circle(bitmap dest, color clr, float xc, float yc, int32_t radius);
void draw_circle(bitmap dest, color clr, bool filled, const point2d &point, int32_t radius);
void draw_circle(color clr, bool filled, float xc, float yc, int32_t radius);
void draw_circle(bitmap dest, color clr, bool filled, float xc, float yc, int32_t radius);
void draw_circle_on_screen(color clr, const circle &c);
void draw_circle_on_screen(color clr, bool filled, const circle &c);
void draw_circle_on_screen(color clr, const point2d &position, int32_t radius);
void draw_circle_on_screen(color clr, bool filled, const point2d &position, int32_t radius);
void draw_circle_on_screen(color clr, bool filled, float xc, float yc, int32_t radius);
void draw_ellipse(color clr, const rectangle &source);
void draw_ellipse(color clr, bool filled, const rectangle &source);
void draw_ellipse(bitmap dest, color clr, const rectangle &source);
void draw_ellipse(bitmap dest, color clr, bool filled, const rectangle &source);
void draw_ellipse(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_ellipse(color clr, bool filled, float xPos, float yPos, int32_t width, int32_t height);
void draw_ellipse(bitmap dest, color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_ellipse_on_screen(color clr, const rectangle &source);
void draw_ellipse_on_screen(color clr, bool filled, const rectangle &source);
void draw_ellipse_on_screen(color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_horizontal_line(bitmap dest, color clr, int32_t y, int32_t x1, int32_t x2);
void draw_line(color clr, const line_segment &line);
void draw_line(color clr, const point2d &startPt, const point2d &endPt);
void draw_line(bitmap dest, color clr, const line_segment &line);
void draw_line(bitmap dest, color clr, const point2d &startPt, const point2d &endPt);
void draw_line(bitmap dest, color clr, int32_t xPosStart, int32_t yPosStart, int32_t xPosEnd, int32_t yPosEnd);
void draw_line_on_screen(color clr, const line_segment &line);
void draw_line_on_screen(color clr, const point2d &startPt, const point2d &endPt);
void draw_lines(color clr, const lines_array lines, int32_t lines_len);
void draw_pixel(color clr, const point2d &position);
void draw_pixel(bitmap dest, color clr, const point2d &position);
void draw_pixel(bitmap dest, color clr, int32_t x, int32_t y);
void draw_pixel_on_screen(color clr, const point2d &position);
void draw_rectangle(color clr, const rectangle &source);
void draw_rectangle(color clr, bool filled, const rectangle &source);
void draw_rectangle(bitmap dest, color clr, const rectangle &source);
void draw_rectangle(bitmap dest, color clr, bool filled, const rectangle &source);
void draw_rectangle(color clr, bool filled, float xPos, float yPos, int32_t width, int32_t height);
void draw_rectangle(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_rectangle(bitmap dest, color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_rectangle_on_screen(color clr, const rectangle &source);
void draw_rectangle_on_screen(color clr, bool filled, const rectangle &source);
void draw_rectangle_on_screen(color clr, bool filled, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void draw_triangle(color clr, const triangle  &tri);
void draw_triangle(color clr, bool filled, const triangle  &tri);
void draw_triangle(bitmap dest, color clr, const triangle  &tri);
void draw_triangle(bitmap dest, color clr, bool filled, const triangle  &tri);
void draw_triangle(bitmap dest, color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void draw_triangle_on_screen(color clr, const triangle  &tri);
void draw_triangle_on_screen(color clr, bool filled, const triangle  &tri);
void draw_vertical_line(bitmap dest, color clr, int32_t x, int32_t y1, int32_t y2);
void fill_circle(color clr, const point2d &position, int32_t radius);
void fill_circle(color clr, const circle &c);
void fill_circle(bitmap dest, color clr, const circle &c);
void fill_circle(bitmap dest, color clr, const point2d &point, int32_t radius);
void fill_circle(bitmap dest, color clr, float xc, float yc, int32_t radius);
void fill_circle_on_screen(color clr, const circle &c);
void fill_circle_on_screen(color clr, const point2d &position, int32_t radius);
void fill_ellipse(color clr, const rectangle &source);
void fill_ellipse(bitmap dest, color clr, const rectangle &source);
void fill_ellipse(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_ellipse_on_screen(color clr, const rectangle &source);
void fill_rectangle(color clr, const rectangle &source);
void fill_rectangle(bitmap dest, color clr, const rectangle &source);
void fill_rectangle(bitmap dest, color clr, int32_t xPos, int32_t yPos, int32_t width, int32_t height);
void fill_rectangle_on_screen(color clr, const rectangle &source);
void fill_triangle(color clr, const triangle  &tri);
void fill_triangle(bitmap dest, color clr, const triangle  &tri);
void fill_triangle(bitmap dest, color clr, float x1, float y1, float x2, float y2, float x3, float y3);
void fill_triangle_on_screen(color clr, const triangle  &tri);
void hsbvalues_of(color c, float &h, float &s, float &b);
void open_graphics_window(const char *caption);
void pop_clip();
void pop_clip(bitmap bmp);
void push_clip(const rectangle &r);
void push_clip(bitmap bmp, const rectangle &r);
void push_clip(int32_t x, int32_t y, int32_t w, int32_t h);
void refresh_screen(uint32_t TargetFPS);
void reset_clip(bitmap bmp);
void set_clip(const rectangle &r);
void set_clip(bitmap bmp, const rectangle &r);
void set_clip(int32_t x, int32_t y, int32_t w, int32_t h);
void set_clip(bitmap bmp, int32_t x, int32_t y, int32_t w, int32_t h);

#endif

#endif

