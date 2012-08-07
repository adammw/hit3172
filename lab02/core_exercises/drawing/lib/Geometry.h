/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Geometry
*
* Wrapping sgGeometry.pas
*/

#ifndef sgGeometry
#define sgGeometry

#include <stdbool.h>
#include <stdint.h>

#include "Types.h"

vector add_vectors(const vector *v1, const vector *v2);
vector add_vectors_byval(const vector v1, const vector v2);
void apply_matrix_to_points(const matrix2d  *m, point2d *pts, int32_t pts_len);
void apply_matrix_to_points_byval(const matrix2d  m, point2d *pts, int32_t pts_len);
void apply_matrix(const matrix2d  *m, triangle  *tri);
void apply_matrix_byval(const matrix2d  m, triangle  *tri);
float calculate_angle_between_vectors(const vector *v1, const vector *v2);
float calculate_angle_between_vectors_byval(const vector v1, const vector v2);
float calculate_angle_between_sprites(sprite s1, sprite s2);
float calculate_angle(float x1, float y1, float x2, float y2);
float calculate_angle_between(const point2d *pt1, const point2d *pt2);
float calculate_angle_between_byval(const point2d pt1, const point2d pt2);
point2d circle_center_point(const circle *c);
point2d circle_center_point_byval(const circle c);
circle circle_from_xy(float x, float y, int32_t radius);
circle circle_at(const point2d *pt, int32_t radius);
circle circle_at_byval(const point2d pt, int32_t radius);
int32_t circle_radius(const circle *c);
int32_t circle_radius_byval(const circle c);
bool circle_within_rect(const circle *c, const rectangle *rect);
bool circle_within_rect_byval(const circle c, const rectangle rect);
float circle_x(const circle *c);
float circle_x_byval(const circle c);
float circle_y(const circle *c);
float circle_y_byval(const circle c);
point2d closest_point_on_circle(const point2d *fromPt, const circle *c);
point2d closest_point_on_circle_byval(const point2d fromPt, const circle c);
point2d closest_point_on_line_xy(float x, float y, const line_segment *line);
point2d closest_point_on_line_xy_byval(float x, float y, const line_segment line);
point2d closest_point_on_line(const point2d *fromPt, const line_segment *line);
point2d closest_point_on_line_byval(const point2d fromPt, const line_segment line);
point2d closest_point_on_line_from_circle(const circle *c, const line_segment *line);
point2d closest_point_on_line_from_circle_byval(const circle c, const line_segment line);
point2d closest_point_on_lines_from_circle(const circle *c, const lines_array lines, int32_t lines_len);
point2d closest_point_on_lines_from_circle_byval(const circle c, const lines_array lines, int32_t lines_len);
point2d closest_point_on_rect_from_circle(const circle *c, const rectangle *rect);
point2d closest_point_on_rect_from_circle_byval(const circle c, const rectangle rect);
float cosine(float angle);
circle create_circle_from_xy(float x, float y, int32_t radius);
circle create_circle(const point2d *pt, int32_t radius);
circle create_circle_byval(const point2d pt, int32_t radius);
line_segment create_line(float x1, float y1, float x2, float y2);
line_segment create_line_point_to_point(const point2d *pt1, const point2d *pt2);
line_segment create_line_point_to_point_byval(const point2d pt1, const point2d pt2);
vector create_line_as_vector(const line_segment *line);
vector create_line_as_vector_byval(const line_segment line);
line_segment create_line_from_vector(const vector *mv);
line_segment create_line_from_vector_byval(const vector mv);
line_segment create_line_vector_with_start_point(const point2d *pt, const vector *mv);
line_segment create_line_vector_with_start_point_byval(const point2d pt, const vector mv);
line_segment create_line_vector_with_start_xy(float x, float y, const vector *mv);
line_segment create_line_vector_with_start_xy_byval(float x, float y, const vector mv);
rectangle create_rectangle(float x, float y, int32_t w, int32_t h);
rectangle create_rectangle_lines(const lines_array lines, int32_t lines_len);
rectangle create_rectangle_triangle(const triangle  *tri);
rectangle create_rectangle_triangle_byval(const triangle  tri);
rectangle create_rectangle_line(const line_segment *line);
rectangle create_rectangle_line_byval(const line_segment line);
rectangle create_rectangle_circle(const circle *c);
rectangle create_rectangle_circle_byval(const circle c);
rectangle create_rectangle_for_points(const point2d *pt1, const point2d *pt2);
rectangle create_rectangle_for_points_byval(const point2d pt1, const point2d pt2);
rectangle create_rectangle_at_point(const point2d *pt, int32_t width, int32_t height);
rectangle create_rectangle_at_point_byval(const point2d pt, int32_t width, int32_t height);
triangle  create_triangle(float ax, float ay, float bx, float by, float cx, float cy);
triangle  create_triangle_points(const point2d *a, const point2d *b, const point2d *c);
triangle  create_triangle_points_byval(const point2d a, const point2d b, const point2d c);
vector create_vector_from_angle(float angle, float magnitude);
vector create_vector_from_point_pt_to_rectangle(const point2d *pt, const rectangle *rect);
vector create_vector_from_point_pt_to_rectangle_byval(const point2d pt, const rectangle rect);
vector create_vector_from_point_to_rectangle(float x, float y, const rectangle *rect);
vector create_vector_from_point_to_rectangle_byval(float x, float y, const rectangle rect);
vector create_vector_from_point_to_rect(float x, float y, float rectX, float rectY, int32_t rectWidth, int32_t rectHeight);
vector create_vector_from_points(const point2d *p1, const point2d *p2);
vector create_vector_from_points_byval(const point2d p1, const point2d p2);
vector create_vector_to_point(const point2d *p1);
vector create_vector_to_point_byval(const point2d p1);
point2d distant_point_on_circle(const point2d *pt, const circle *c);
point2d distant_point_on_circle_byval(const point2d pt, const circle c);
bool distant_point_on_circle_heading(const point2d *pt, const circle *c, const vector *heading, point2d *oppositePt);
bool distant_point_on_circle_heading_byval(const point2d pt, const circle c, const vector heading, point2d *oppositePt);
float dot_product(const vector *v1, const vector *v2);
float dot_product_byval(const vector v1, const vector v2);
void fix_rectangle(rectangle *rect);
void fix_rect(float *x, float *y, int32_t *width, int32_t *height);
matrix2d  identity_matrix();
rectangle inset_rectangle(const rectangle *rect, int32_t insetAmount);
rectangle inset_rectangle_byval(const rectangle rect, int32_t insetAmount);
rectangle intersection(const rectangle *rect1, const rectangle *rect2);
rectangle intersection_byval(const rectangle rect1, const rectangle rect2);
vector invert_vector(const vector *v);
vector invert_vector_byval(const vector v);
vector limit_vector(const vector *v, float limit);
vector limit_vector_byval(const vector v, float limit);
vector line_as_vector(const line_segment *line);
vector line_as_vector_byval(const line_segment line);
bool line_circle_hit(const circle *c, const vector *velocity, const lines_array lines, line_segment *found, int32_t lines_len);
bool line_circle_hit_byval(const circle c, const vector velocity, const lines_array lines, line_segment *found, int32_t lines_len);
line_segment line_from(float x1, float y1, float x2, float y2);
line_segment line_from_point_to_point(const point2d *pt1, const point2d *pt2);
line_segment line_from_point_to_point_byval(const point2d pt1, const point2d pt2);
line_segment line_from_vector(const vector *mv);
line_segment line_from_vector_byval(const vector mv);
line_segment line_from_vector_with_start_point(const point2d *pt, const vector *mv);
line_segment line_from_vector_with_start_point_byval(const point2d pt, const vector mv);
line_segment line_from_vector_with_start_xy(float x, float y, const vector *mv);
line_segment line_from_vector_with_start_xy_byval(float x, float y, const vector mv);
bool line_intersection_point(const line_segment *line1, const line_segment *line2, point2d *pt);
bool line_intersection_point_byval(const line_segment line1, const line_segment line2, point2d *pt);
bool line_intersects_circle(const line_segment *l, const circle *c);
bool line_intersects_circle_byval(const line_segment l, const circle c);
bool line_intersects_lines(const line_segment *line, const lines_array lines, int32_t lines_len);
bool line_intersects_lines_byval(const line_segment line, const lines_array lines, int32_t lines_len);
bool line_intersects_rect(const line_segment *line, const rectangle *rect);
bool line_intersects_rect_byval(const line_segment line, const rectangle rect);
float line_magnitude_sq_from_line(const line_segment *line);
float line_magnitude_sq_from_line_byval(const line_segment line);
float line_magnitude_sq(float x1, float y1, float x2, float y2);
point2d line_mid_point(const line_segment *line);
point2d line_mid_point_byval(const line_segment line);
vector line_normal(const line_segment *line);
vector line_normal_byval(const line_segment line);
bool line_segments_intersect(const line_segment *line1, const line_segment *line2);
bool line_segments_intersect_byval(const line_segment line1, const line_segment line2);
void line_to_string(const line_segment *ln, char *result);
void line_to_string_byval(const line_segment ln, char *result);
void lines_from_rect(const rectangle *rect, lines_array result, int32_t result_len);
void lines_from_rect_byval(const rectangle rect, lines_array result, int32_t result_len);
void lines_from_triangle(const triangle  *tri, lines_array result, int32_t result_len);
void lines_from_triangle_byval(const triangle  tri, lines_array result, int32_t result_len);
bool lines_rect_intersect(const lines_array lines, const rectangle *r, int32_t lines_len);
bool lines_rect_intersect_byval(const lines_array lines, const rectangle r, int32_t lines_len);
vector matrix_multiply_vector(const matrix2d  *m, const vector *v);
vector matrix_multiply_vector_byval(const matrix2d  m, const vector v);
matrix2d  matrix_multiply(const matrix2d  *m1, const matrix2d  *m2);
matrix2d  matrix_multiply_byval(const matrix2d  m1, const matrix2d  m2);
void matrix_to_string(const matrix2d  *m, char *result);
void matrix_to_string_byval(const matrix2d  m, char *result);
point2d point_add(const point2d *pt1, const point2d *pt2);
point2d point_add_byval(const point2d pt1, const point2d pt2);
point2d point_at(float x, float y);
point2d point_at_start_with_offset(const point2d *startPoint, const vector *offset);
point2d point_at_start_with_offset_byval(const point2d startPoint, const vector offset);
bool point_in_circle(const point2d *pt, const circle *c);
bool point_in_circle_byval(const point2d pt, const circle c);
bool point_xyin_circle(float ptX, float ptY, float cX, float cY, float radius);
bool point_in_rect(const point2d *pt, const rectangle *rect);
bool point_in_rect_byval(const point2d pt, const rectangle rect);
bool point_xyin_rect(float x, float y, const rectangle *rect);
bool point_xyin_rect_byval(float x, float y, const rectangle rect);
bool point_in_rect_xy(const point2d *pt, float x, float y, float w, float h);
bool point_in_rect_xy_byval(const point2d pt, float x, float y, float w, float h);
bool point_xyin_rect_xy(float ptX, float ptY, float x, float y, float w, float h);
bool point_in_triangle(const point2d *pt, const triangle  *tri);
bool point_in_triangle_byval(const point2d pt, const triangle  tri);
float point_xyline_distance(float x, float y, const line_segment *line);
float point_xyline_distance_byval(float x, float y, const line_segment line);
float point_line_distance(const point2d *pt, const line_segment *line);
float point_line_distance_byval(const point2d pt, const line_segment line);
bool point_on_line(const point2d *pt, const line_segment *line);
bool point_on_line_byval(const point2d pt, const line_segment line);
bool point_on_point(const point2d *pt1, const point2d *pt2);
bool point_on_point_byval(const point2d pt1, const point2d pt2);
float point_point_distance(const point2d *pt1, const point2d *pt2);
float point_point_distance_byval(const point2d pt1, const point2d pt2);
void point_to_string(const point2d *pt, char *result);
void point_to_string_byval(const point2d pt, char *result);
void points_from_rect(const rectangle *rect, point2d *result, int32_t result_len);
void points_from_rect_byval(const rectangle rect, point2d *result, int32_t result_len);
void points_from_line(const line_segment *line, point2d *result, int32_t result_len);
void points_from_line_byval(const line_segment line, point2d *result, int32_t result_len);
point2d random_screen_point();
float ray_circle_intersect_distance(const point2d *ray_origin, const vector *ray_heading, const circle *c);
float ray_circle_intersect_distance_byval(const point2d ray_origin, const vector ray_heading, const circle c);
bool ray_intersection_point(const point2d *fromPt, const vector *heading, const line_segment *line, point2d *pt);
bool ray_intersection_point_byval(const point2d fromPt, const vector heading, const line_segment line, point2d *pt);
rectangle rectangle_after_move(const rectangle *rect, const vector *mv);
rectangle rectangle_after_move_byval(const rectangle rect, const vector mv);
float rectangle_bottom(const rectangle *rect);
float rectangle_bottom_byval(const rectangle rect);
point2d rectangle_bottom_left(const rectangle *rect);
point2d rectangle_bottom_left_byval(const rectangle rect);
point2d rectangle_bottom_right(const rectangle *rect);
point2d rectangle_bottom_right_byval(const rectangle rect);
point2d rectangle_center(const rectangle *rect);
point2d rectangle_center_byval(const rectangle rect);
point2d rectangle_center_bottom(const rectangle *rect);
point2d rectangle_center_bottom_byval(const rectangle rect);
point2d rectangle_center_left(const rectangle *rect);
point2d rectangle_center_left_byval(const rectangle rect);
point2d rectangle_center_right(const rectangle *rect);
point2d rectangle_center_right_byval(const rectangle rect);
point2d rectangle_center_top(const rectangle *rect);
point2d rectangle_center_top_byval(const rectangle rect);
rectangle rectangle_from(float x, float y, int32_t w, int32_t h);
rectangle rectangle_from_triangle(const triangle  *tri);
rectangle rectangle_from_triangle_byval(const triangle  tri);
rectangle rectangle_from_lines(const lines_array lines, int32_t lines_len);
rectangle rectangle_from_line(const line_segment *line);
rectangle rectangle_from_line_byval(const line_segment line);
rectangle rectangle_from_circle(const circle *c);
rectangle rectangle_from_circle_byval(const circle c);
rectangle rectangle_for_points(const point2d *pt1, const point2d *pt2);
rectangle rectangle_for_points_byval(const point2d pt1, const point2d pt2);
rectangle rectangle_at_point(const point2d *pt, int32_t width, int32_t height);
rectangle rectangle_at_point_byval(const point2d pt, int32_t width, int32_t height);
float rectangle_left(const rectangle *rect);
float rectangle_left_byval(const rectangle rect);
rectangle rectangle_offset(const rectangle *rect, const vector *vec);
rectangle rectangle_offset_byval(const rectangle rect, const vector vec);
float rectangle_right(const rectangle *rect);
float rectangle_right_byval(const rectangle rect);
void rectangle_to_string(const rectangle *rect, char *result);
void rectangle_to_string_byval(const rectangle rect, char *result);
float rectangle_top(const rectangle *rect);
float rectangle_top_byval(const rectangle rect);
point2d rectangle_top_left(const rectangle *rect);
point2d rectangle_top_left_byval(const rectangle rect);
point2d rectangle_top_right(const rectangle *rect);
point2d rectangle_top_right_byval(const rectangle rect);
bool rectangles_intersect(const rectangle *rect1, const rectangle *rect2);
bool rectangles_intersect_byval(const rectangle rect1, const rectangle rect2);
matrix2d  rotation_matrix(float deg);
matrix2d  scale_matrix(float scale);
matrix2d  scale_matrix_by_point(const point2d *scale);
matrix2d  scale_matrix_by_point_byval(const point2d scale);
matrix2d  scale_rotate_translate_matrix(const point2d *scale, float deg, const point2d *translate);
matrix2d  scale_rotate_translate_matrix_byval(const point2d scale, float deg, const point2d translate);
float sine(float angle);
vector subtract_vectors(const vector *v1, const vector *v2);
vector subtract_vectors_byval(const vector v1, const vector v2);
float tangent(float angle);
bool tangent_points(const point2d *fromPt, const circle *c, point2d *p1, point2d *p2);
bool tangent_points_byval(const point2d fromPt, const circle c, point2d *p1, point2d *p2);
matrix2d  translation_matrix(float dx, float dy);
matrix2d  translation_matrix_pt(const point2d *pt);
matrix2d  translation_matrix_pt_byval(const point2d pt);
point2d triangle_barycenter(const triangle  *tri);
point2d triangle_barycenter_byval(const triangle  tri);
triangle  triangle_from(float ax, float ay, float bx, float by, float cx, float cy);
triangle  triangle_from_points(const point2d *a, const point2d *b, const point2d *c);
triangle  triangle_from_points_byval(const point2d a, const point2d b, const point2d c);
bool triangle_rectangle_intersect(const triangle  *tri, const rectangle *rect);
bool triangle_rectangle_intersect_byval(const triangle  tri, const rectangle rect);
void triangle_to_string(const triangle  *tri, char *result);
void triangle_to_string_byval(const triangle  tri, char *result);
bool triangles_rectangle_intersect(const triangle_array tri, const rectangle *rect, int32_t tri_len);
bool triangles_rectangle_intersect_byval(const triangle_array tri, const rectangle rect, int32_t tri_len);
vector unit_vector(const vector *v);
vector unit_vector_byval(const vector v);
float vector_angle(const vector *v);
float vector_angle_byval(const vector v);
vector vector_from_angle(float angle, float magnitude);
vector vector_from_point_pt_to_rectangle(const point2d *pt, const rectangle *rect);
vector vector_from_point_pt_to_rectangle_byval(const point2d pt, const rectangle rect);
vector vector_from_point_to_rectangle(float x, float y, const rectangle *rect);
vector vector_from_point_to_rectangle_byval(float x, float y, const rectangle rect);
vector vector_from_point_to_rect(float x, float y, float rectX, float rectY, int32_t rectWidth, int32_t rectHeight);
vector vector_from_points(const point2d *p1, const point2d *p2);
vector vector_from_points_byval(const point2d p1, const point2d p2);
bool vector_in_rect(const vector *v, const rectangle *rect);
bool vector_in_rect_byval(const vector v, const rectangle rect);
bool vector_in_rect_xy(const vector *v, float x, float y, float w, float h);
bool vector_in_rect_xy_byval(const vector v, float x, float y, float w, float h);
bool vector_is_zero(const vector *v);
bool vector_is_zero_byval(const vector v);
float vector_magnitude(const vector *v);
float vector_magnitude_byval(const vector v);
float vector_magnitude_sq(const vector *v);
float vector_magnitude_sq_byval(const vector v);
vector vector_multiply(const vector *v, float s);
vector vector_multiply_byval(const vector v, float s);
vector vector_normal(const vector *v);
vector vector_normal_byval(const vector v);
vector vector_out_of_circle_from_circle(const circle *src, const circle *bounds, const vector *velocity);
vector vector_out_of_circle_from_circle_byval(const circle src, const circle bounds, const vector velocity);
vector vector_out_of_circle_from_point(const point2d *pt, const circle *c, const vector *velocity);
vector vector_out_of_circle_from_point_byval(const point2d pt, const circle c, const vector velocity);
vector vector_out_of_rect_from_circle(const circle *c, const rectangle *rect, const vector *velocity);
vector vector_out_of_rect_from_circle_byval(const circle c, const rectangle rect, const vector velocity);
vector vector_out_of_rect_from_point(const point2d *pt, const rectangle *rect, const vector *velocity);
vector vector_out_of_rect_from_point_byval(const point2d pt, const rectangle rect, const vector velocity);
vector vector_out_of_rect_from_rect(const rectangle *src, const rectangle *bounds, const vector *velocity);
vector vector_out_of_rect_from_rect_byval(const rectangle src, const rectangle bounds, const vector velocity);
vector vector_over_lines_from_circle(const circle *c, const lines_array lines, const vector *velocity, int32_t *maxIdx, int32_t lines_len);
vector vector_over_lines_from_circle_byval(const circle c, const lines_array lines, const vector velocity, int32_t *maxIdx, int32_t lines_len);
vector vector_over_lines_from_lines(const lines_array srcLines, const lines_array boundLines, const vector *velocity, int32_t *maxIdx, int32_t srcLines_len, int32_t boundLines_len);
vector vector_over_lines_from_lines_byval(const lines_array srcLines, const lines_array boundLines, const vector velocity, int32_t *maxIdx, int32_t srcLines_len, int32_t boundLines_len);
vector vector_to(float x, float y);
vector vector_to_with_invert_y(float x, float y, bool invertY);
vector vector_to_point(const point2d *p1);
vector vector_to_point_byval(const point2d p1);
bool vectors_equal(const vector *v1, const vector *v2);
bool vectors_equal_byval(const vector v1, const vector v2);
bool vectors_not_equal(const vector *v1, const vector *v2);
bool vectors_not_equal_byval(const vector v1, const vector v2);
void widest_points(const circle *c, const vector *along, point2d *pt1, point2d *pt2);
void widest_points_byval(const circle c, const vector along, point2d *pt1, point2d *pt2);

#ifdef __cplusplus
// C++ overloaded functions
vector add_vectors(const vector &v1, const vector &v2);
void apply_matrix(const matrix2d  &m, point2d *pts, int32_t pts_len);
void apply_matrix(const matrix2d  &m, triangle  &tri);
float calculate_angle(const vector &v1, const vector &v2);
float calculate_angle(sprite s1, sprite s2);
float calculate_angle_between(const point2d &pt1, const point2d &pt2);
point2d center_point(const circle &c);
circle circle_at(float x, float y, int32_t radius);
circle circle_at(const point2d &pt, int32_t radius);
int32_t circle_radius(const circle &c);
bool circle_within_rect(const circle &c, const rectangle &rect);
float circle_x(const circle &c);
float circle_y(const circle &c);
point2d closest_point_on_circle(const point2d &fromPt, const circle &c);
point2d closest_point_on_line(float x, float y, const line_segment &line);
point2d closest_point_on_line(const point2d &fromPt, const line_segment &line);
point2d closest_point_on_line_from_circle(const circle &c, const line_segment &line);
point2d closest_point_on_lines_from_circle(const circle &c, const lines_array lines, int32_t lines_len);
point2d closest_point_on_rect_from_circle(const circle &c, const rectangle &rect);
circle create_circle(float x, float y, int32_t radius);
circle create_circle(const point2d &pt, int32_t radius);
line_segment create_line(const point2d &pt1, const point2d &pt2);
vector create_line_as_vector(const line_segment &line);
line_segment create_line_from_vector(const vector &mv);
line_segment create_line_from_vector(const point2d &pt, const vector &mv);
line_segment create_line_from_vector(float x, float y, const vector &mv);
rectangle create_rectangle(const lines_array lines, int32_t lines_len);
rectangle create_rectangle(const triangle  &tri);
rectangle create_rectangle(const line_segment &line);
rectangle create_rectangle(const circle &c);
rectangle create_rectangle(const point2d &pt1, const point2d &pt2);
rectangle create_rectangle(const point2d &pt, int32_t width, int32_t height);
triangle  create_triangle(const point2d &a, const point2d &b, const point2d &c);
vector create_vector_from_point_to_rect(const point2d &pt, const rectangle &rect);
vector create_vector_from_point_to_rect(float x, float y, const rectangle &rect);
vector create_vector_from_points(const point2d &p1, const point2d &p2);
vector create_vector_to_point(const point2d &p1);
point2d distant_point_on_circle(const point2d &pt, const circle &c);
bool distant_point_on_circle_heading(const point2d &pt, const circle &c, const vector &heading, point2d &oppositePt);
float dot_product(const vector &v1, const vector &v2);
void fix_rectangle(rectangle &rect);
void fix_rectangle(float &x, float &y, int32_t &width, int32_t &height);
rectangle inset_rectangle(const rectangle &rect, int32_t insetAmount);
rectangle intersection(const rectangle &rect1, const rectangle &rect2);
vector invert_vector(const vector &v);
vector limit_vector(const vector &v, float limit);
vector line_as_vector(const line_segment &line);
bool line_circle_hit(const circle &c, const vector &velocity, const lines_array lines, line_segment &found, int32_t lines_len);
line_segment line_from(const point2d &pt1, const point2d &pt2);
line_segment line_from_vector(const vector &mv);
line_segment line_from_vector(const point2d &pt, const vector &mv);
line_segment line_from_vector(float x, float y, const vector &mv);
bool line_intersection_point(const line_segment &line1, const line_segment &line2, point2d &pt);
bool line_intersects_circle(const line_segment &l, const circle &c);
bool line_intersects_lines(const line_segment &line, const lines_array lines, int32_t lines_len);
bool line_intersects_rect(const line_segment &line, const rectangle &rect);
float line_magnitude_sq(const line_segment &line);
point2d line_mid_point(const line_segment &line);
vector line_normal(const line_segment &line);
bool line_segments_intersect(const line_segment &line1, const line_segment &line2);
void line_to_string(const line_segment &ln, char *result);
void lines_from(const rectangle &rect, lines_array result, int32_t result_len);
void lines_from(const triangle  &tri, lines_array result, int32_t result_len);
bool lines_rect_intersect(const lines_array lines, const rectangle &r, int32_t lines_len);
vector matrix_multiply(const matrix2d  &m, const vector &v);
matrix2d  matrix_multiply(const matrix2d  &m1, const matrix2d  &m2);
void matrix_to_string(const matrix2d  &m, char *result);
point2d point_add(const point2d &pt1, const point2d &pt2);
point2d point_at(const point2d &startPoint, const vector &offset);
bool point_in_circle(const point2d &pt, const circle &c);
bool point_in_circle(float ptX, float ptY, float cX, float cY, float radius);
bool point_in_rect(const point2d &pt, const rectangle &rect);
bool point_in_rect(float x, float y, const rectangle &rect);
bool point_in_rect(const point2d &pt, float x, float y, float w, float h);
bool point_in_rect(float ptX, float ptY, float x, float y, float w, float h);
bool point_in_triangle(const point2d &pt, const triangle  &tri);
float point_line_distance(float x, float y, const line_segment &line);
float point_line_distance(const point2d &pt, const line_segment &line);
bool point_on_line(const point2d &pt, const line_segment &line);
bool point_on_point(const point2d &pt1, const point2d &pt2);
float point_point_distance(const point2d &pt1, const point2d &pt2);
void point_to_string(const point2d &pt, char *result);
void points_from(const rectangle &rect, point2d *result, int32_t result_len);
void points_from(const line_segment &line, point2d *result, int32_t result_len);
float ray_circle_intersect_distance(const point2d &ray_origin, const vector &ray_heading, const circle &c);
bool ray_intersection_point(const point2d &fromPt, const vector &heading, const line_segment &line, point2d &pt);
rectangle rectangle_after_move(const rectangle &rect, const vector &mv);
float rectangle_bottom(const rectangle &rect);
point2d rectangle_bottom_left(const rectangle &rect);
point2d rectangle_bottom_right(const rectangle &rect);
point2d rectangle_center(const rectangle &rect);
point2d rectangle_center_bottom(const rectangle &rect);
point2d rectangle_center_left(const rectangle &rect);
point2d rectangle_center_right(const rectangle &rect);
point2d rectangle_center_top(const rectangle &rect);
rectangle rectangle_from(const triangle  &tri);
rectangle rectangle_from(const lines_array lines, int32_t lines_len);
rectangle rectangle_from(const line_segment &line);
rectangle rectangle_from(const circle &c);
rectangle rectangle_from(const point2d &pt1, const point2d &pt2);
rectangle rectangle_from(const point2d &pt, int32_t width, int32_t height);
float rectangle_left(const rectangle &rect);
rectangle rectangle_offset(const rectangle &rect, const vector &vec);
float rectangle_right(const rectangle &rect);
void rectangle_to_string(const rectangle &rect, char *result);
float rectangle_top(const rectangle &rect);
point2d rectangle_top_left(const rectangle &rect);
point2d rectangle_top_right(const rectangle &rect);
bool rectangles_intersect(const rectangle &rect1, const rectangle &rect2);
matrix2d  scale_matrix(const point2d &scale);
matrix2d  scale_rotate_translate_matrix(const point2d &scale, float deg, const point2d &translate);
vector subtract_vectors(const vector &v1, const vector &v2);
bool tangent_points(const point2d &fromPt, const circle &c, point2d &p1, point2d &p2);
matrix2d  translation_matrix(const point2d &pt);
point2d triangle_barycenter(const triangle  &tri);
triangle  triangle_from(const point2d &a, const point2d &b, const point2d &c);
bool triangle_rectangle_intersect(const triangle  &tri, const rectangle &rect);
void triangle_to_string(const triangle  &tri, char *result);
bool triangles_rectangle_intersect(const triangle_array tri, const rectangle &rect, int32_t tri_len);
vector unit_vector(const vector &v);
float vector_angle(const vector &v);
vector vector_from_point_to_rect(const point2d &pt, const rectangle &rect);
vector vector_from_point_to_rect(float x, float y, const rectangle &rect);
vector vector_from_points(const point2d &p1, const point2d &p2);
bool vector_in_rect(const vector &v, const rectangle &rect);
bool vector_in_rect(const vector &v, float x, float y, float w, float h);
bool vector_is_zero(const vector &v);
float vector_magnitude(const vector &v);
float vector_magnitude_sq(const vector &v);
vector vector_multiply(const vector &v, float s);
vector vector_normal(const vector &v);
vector vector_out_of_circle_from_circle(const circle &src, const circle &bounds, const vector &velocity);
vector vector_out_of_circle_from_point(const point2d &pt, const circle &c, const vector &velocity);
vector vector_out_of_rect_from_circle(const circle &c, const rectangle &rect, const vector &velocity);
vector vector_out_of_rect_from_point(const point2d &pt, const rectangle &rect, const vector &velocity);
vector vector_out_of_rect_from_rect(const rectangle &src, const rectangle &bounds, const vector &velocity);
vector vector_over_lines_from_circle(const circle &c, const lines_array lines, const vector &velocity, int32_t &maxIdx, int32_t lines_len);
vector vector_over_lines_from_lines(const lines_array srcLines, const lines_array boundLines, const vector &velocity, int32_t &maxIdx, int32_t srcLines_len, int32_t boundLines_len);
vector vector_to(float x, float y, bool invertY);
vector vector_to_point(const point2d &p1);
bool vectors_equal(const vector &v1, const vector &v2);
bool vectors_not_equal(const vector &v1, const vector &v2);
void widest_points(const circle &c, const vector &along, point2d &pt1, point2d &pt2);

#endif

#endif

