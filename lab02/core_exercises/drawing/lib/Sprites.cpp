/*
* Generated by SGWrapperGen - DO NOT EDIT!
*
* SwinGame wrapper for C - Sprites
*
* Wrapping sgSprites.pas
*/

#include "SGSDK.h"
#include "Sprites.h"

#include "Types.h"

point2d center_point(sprite s)
{
    return sg_Sprites_CenterPoint(s);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer)
{
    return sg_Sprites_CreateBasicSprite(layer);
}

#endif

sprite create_basic_sprite(bitmap layer)
{
    return sg_Sprites_CreateBasicSprite(layer);
}

#ifdef __cplusplus

sprite create_sprite(const bitmap *layers, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSprite(layers, layers_len);
}

#endif

sprite create_layered_sprite(const bitmap *layers, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSprite(layers, layers_len);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, const char *layerName)
{
    return sg_Sprites_CreateSpriteWithLayer(layer, layerName);
}

#endif

sprite create_sprite_with_layer(bitmap layer, const char *layerName)
{
    return sg_Sprites_CreateSpriteWithLayer(layer, layerName);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, point2d pt)
{
    return sg_Sprites_CreateBasicSpritePt(layer, pt);
}

#endif

sprite create_basic_sprite_pt(bitmap layer, point2d pt)
{
    return sg_Sprites_CreateBasicSpritePt(layer, pt);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, bitmap layer)
{
    return sg_Sprites_CreateBasicSpriteNamed(name, layer);
}

#endif

sprite create_basic_sprite_named(const char *name, bitmap layer)
{
    return sg_Sprites_CreateBasicSpriteNamed(name, layer);
}

#ifdef __cplusplus

sprite create_sprite(const bitmap *layers, const string_array layerNames, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNames(layers, layerNames, layers_len, layerNames_len);
}

#endif

sprite create_layered_sprite_with_layer_names(const bitmap *layers, const string_array layerNames, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNames(layers, layerNames, layers_len, layerNames_len);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithAnimation(layer, ani);
}

#endif

sprite create_sprite_with_animation(bitmap layer, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithAnimation(layer, ani);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, const bitmap *layers, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteNamed(name, layers, layers_len);
}

#endif

sprite create_layered_sprite_named(const char *name, const bitmap *layers, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteNamed(name, layers, layers_len);
}

#ifdef __cplusplus

sprite create_sprite(const bitmap *layers, animation_script ani, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteWithAnimationScript(layers, ani, layers_len);
}

#endif

sprite create_layered_sprite_with_animation_script(const bitmap *layers, animation_script ani, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteWithAnimationScript(layers, ani, layers_len);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, bitmap layer, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithAnimationNamed(name, layer, ani);
}

#endif

sprite create_sprite_with_animation_named(const char *name, bitmap layer, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithAnimationNamed(name, layer, ani);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, animation_script ani, point2d pt)
{
    return sg_Sprites_CreateSpriteWithAnimationPt(layer, ani, pt);
}

#endif

sprite create_sprite_with_animation_pt(bitmap layer, animation_script ani, point2d pt)
{
    return sg_Sprites_CreateSpriteWithAnimationPt(layer, ani, pt);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, bitmap layer, const char *layerName)
{
    return sg_Sprites_CreateSpriteWithLayerNamed(name, layer, layerName);
}

#endif

sprite create_sprite_with_layer_named(const char *name, bitmap layer, const char *layerName)
{
    return sg_Sprites_CreateSpriteWithLayerNamed(name, layer, layerName);
}

#ifdef __cplusplus

sprite create_sprite(const bitmap *layers, const string_array layerNames, animation_script ani, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesAndAnimationScript(layers, layerNames, ani, layers_len, layerNames_len);
}

#endif

sprite create_layered_sprite_with_layer_names_and_animation_script(const bitmap *layers, const string_array layerNames, animation_script ani, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesAndAnimationScript(layers, layerNames, ani, layers_len, layerNames_len);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, const char *layerName, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithLayerAndAnimation(layer, layerName, ani);
}

#endif

sprite create_sprite_with_layer_and_animation(bitmap layer, const char *layerName, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithLayerAndAnimation(layer, layerName, ani);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, const bitmap *layers, const string_array layerNames, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesNamed(name, layers, layerNames, layers_len, layerNames_len);
}

#endif

sprite create_layered_sprite_with_layer_names_named(const char *name, const bitmap *layers, const string_array layerNames, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesNamed(name, layers, layerNames, layers_len, layerNames_len);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, const bitmap *layers, animation_script ani, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteWithAnimationScriptNamed(name, layers, ani, layers_len);
}

#endif

sprite create_layered_sprite_with_animation_script_named(const char *name, const bitmap *layers, animation_script ani, int32_t layers_len)
{
    return sg_Sprites_CreateLayeredSpriteWithAnimationScriptNamed(name, layers, ani, layers_len);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, float x, float y)
{
    return sg_Sprites_CreateBasicSpriteXY(layer, x, y);
}

#endif

sprite create_basic_sprite_xy(bitmap layer, float x, float y)
{
    return sg_Sprites_CreateBasicSpriteXY(layer, x, y);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, bitmap layer, const char *layerName, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithLayerAndAnimationNamed(name, layer, layerName, ani);
}

#endif

sprite create_sprite_with_layer_and_animation_named(const char *name, bitmap layer, const char *layerName, animation_script ani)
{
    return sg_Sprites_CreateSpriteWithLayerAndAnimationNamed(name, layer, layerName, ani);
}

#ifdef __cplusplus

sprite create_sprite(bitmap layer, animation_script ani, float x, float y)
{
    return sg_Sprites_CreateSpriteWithAnimationXY(layer, ani, x, y);
}

#endif

sprite create_sprite_with_animation_xy(bitmap layer, animation_script ani, float x, float y)
{
    return sg_Sprites_CreateSpriteWithAnimationXY(layer, ani, x, y);
}

#ifdef __cplusplus

sprite create_sprite(const char *name, const bitmap *layers, const string_array layerNames, animation_script ani, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesAndAnimationScriptNamed(name, layers, layerNames, ani, layers_len, layerNames_len);
}

#endif

sprite create_layered_sprite_with_layer_names_and_animation_script_named(const char *name, const bitmap *layers, const string_array layerNames, animation_script ani, int32_t layers_len, int32_t layerNames_len)
{
    return sg_Sprites_CreateLayeredSpriteWithLayerNamesAndAnimationScriptNamed(name, layers, layerNames, ani, layers_len, layerNames_len);
}

void draw_sprite(sprite s)
{
    sg_Sprites_DrawSpriteOffsetXY(s, 0, 0);
}

#ifdef __cplusplus

void draw_sprite(sprite s, const point2d &position)
{
    sg_Sprites_DrawSpriteOffsetPoint(s, &position);
}

#endif

void draw_sprite_offset_point(sprite s, const point2d *position)
{
    sg_Sprites_DrawSpriteOffsetPoint(s, position);
}

void draw_sprite_offset_point_byval(sprite s, const point2d position)
{
    sg_Sprites_DrawSpriteOffsetPoint(s, &position);
}

#ifdef __cplusplus

void draw_sprite(sprite s, int32_t xOffset, int32_t yOffset)
{
    sg_Sprites_DrawSpriteOffsetXY(s, xOffset, yOffset);
}

#endif

void draw_sprite_offset_xy(sprite s, int32_t xOffset, int32_t yOffset)
{
    sg_Sprites_DrawSpriteOffsetXY(s, xOffset, yOffset);
}

#ifdef __cplusplus

void free_sprite(sprite &s)
{
    sg_Sprites_FreeSprite(&s);
}

#endif

void free_sprite(sprite *s)
{
    sg_Sprites_FreeSprite(s);
}

bool has_sprite(const char *name)
{
    return sg_Sprites_HasSprite(name) != 0;
}

void move_sprite(sprite s)
{
    sg_Sprites_MoveSpritePct(s, 1.0);
}

#ifdef __cplusplus

void move_sprite(sprite s, const vector &distance)
{
    sg_Sprites_MoveSpriteVecPct(s, &distance, 1.0);
}

#endif

void move_sprite_vec(sprite s, const vector *distance)
{
    sg_Sprites_MoveSpriteVecPct(s, distance, 1.0);
}

void move_sprite_vec_byval(sprite s, const vector distance)
{
    sg_Sprites_MoveSpriteVecPct(s, &distance, 1.0);
}

#ifdef __cplusplus

void move_sprite(sprite s, float pct)
{
    sg_Sprites_MoveSpritePct(s, pct);
}

#endif

void move_sprite_pct(sprite s, float pct)
{
    sg_Sprites_MoveSpritePct(s, pct);
}

#ifdef __cplusplus

void move_sprite(sprite s, const vector &distance, float pct)
{
    sg_Sprites_MoveSpriteVecPct(s, &distance, pct);
}

#endif

void move_sprite_vec_pct(sprite s, const vector *distance, float pct)
{
    sg_Sprites_MoveSpriteVecPct(s, distance, pct);
}

void move_sprite_vec_pct_byval(sprite s, const vector distance, float pct)
{
    sg_Sprites_MoveSpriteVecPct(s, &distance, pct);
}

void move_sprite_to(sprite s, int32_t x, int32_t y)
{
    sg_Sprites_MoveSpriteTo(s, x, y);
}

void release_all_sprites()
{
    sg_Sprites_ReleaseAllSprites();
}

void release_sprite(const char *name)
{
    sg_Sprites_ReleaseSprite(name);
}

int32_t sprite_add_layer(sprite s, bitmap newLayer, const char *layerName)
{
    return sg_Sprites_SpriteAddLayer(s, newLayer, layerName);
}

#ifdef __cplusplus

void sprite_add_to_velocity(sprite s, const vector &value)
{
    sg_Sprites_SpriteAddToVelocity(s, &value);
}

#endif

void sprite_add_to_velocity(sprite s, const vector *value)
{
    sg_Sprites_SpriteAddToVelocity(s, value);
}

void sprite_add_to_velocity_byval(sprite s, const vector value)
{
    sg_Sprites_SpriteAddToVelocity(s, &value);
}

void sprite_add_value(sprite s, const char *name)
{
    sg_Sprites_SpriteAddValue(s, name);
}

#ifdef __cplusplus

void sprite_add_value(sprite s, const char *name, float initVal)
{
    sg_Sprites_SpriteAddValueWithInitialValue(s, name, initVal);
}

#endif

void sprite_add_value_with_initial_value(sprite s, const char *name, float initVal)
{
    sg_Sprites_SpriteAddValueWithInitialValue(s, name, initVal);
}

bool sprite_animation_has_ended(sprite s)
{
    return sg_Sprites_SpriteAnimationHasEnded(s) != 0;
}

void sprite_bring_layer_forward(sprite s, int32_t visibleLayer)
{
    sg_Sprites_SpriteBringLayerForward(s, visibleLayer);
}

void sprite_bring_layer_to_front(sprite s, int32_t visibleLayer)
{
    sg_Sprites_SpriteBringLayerToFront(s, visibleLayer);
}

circle sprite_circle(sprite s)
{
    return sg_Sprites_SpriteCircle(s);
}

bitmap sprite_collision_bitmap(sprite s)
{
    return sg_Sprites_SpriteCollisionBitmap(s);
}

circle sprite_collision_circle(sprite s)
{
    return sg_Sprites_SpriteCollisionCircle(s);
}

collision_test_kind sprite_collision_kind(sprite s)
{
    return sg_Sprites_SpriteCollisionKind(s);
}

rectangle sprite_collision_rectangle(sprite s)
{
    return sg_Sprites_SpriteCollisionRectangle(s);
}

int32_t sprite_current_cell(sprite s)
{
    return sg_Sprites_SpriteCurrentCell(s);
}

rectangle sprite_current_cell_rectangle(sprite s)
{
    return sg_Sprites_SpriteCurrentCellRectangle(s);
}

float sprite_dx(sprite s)
{
    return sg_Sprites_SpriteDX(s);
}

float sprite_dy(sprite s)
{
    return sg_Sprites_SpriteDY(s);
}

float sprite_heading(sprite s)
{
    return sg_Sprites_SpriteHeading(s);
}

int32_t sprite_height(sprite s)
{
    return sg_Sprites_SpriteHeight(s);
}

#ifdef __cplusplus

void sprite_hide_layer(sprite s, const char *name)
{
    sg_Sprites_SpriteHideLayerNamed(s, name);
}

#endif

void sprite_hide_layer_named(sprite s, const char *name)
{
    sg_Sprites_SpriteHideLayerNamed(s, name);
}

void sprite_hide_layer(sprite s, int32_t id)
{
    sg_Sprites_SpriteHideLayer(s, id);
}

#ifdef __cplusplus

bitmap sprite_layer(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerAtIdx(s, idx);
}

#endif

bitmap sprite_layer_at_idx(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerAtIdx(s, idx);
}

#ifdef __cplusplus

bitmap sprite_layer(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamed(s, name);
}

#endif

bitmap sprite_layer_named(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamed(s, name);
}

circle sprite_layer_circle(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerCircle(s, idx);
}

#ifdef __cplusplus

circle sprite_layer_circle(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedCircle(s, name);
}

#endif

circle sprite_layer_named_circle(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedCircle(s, name);
}

int32_t sprite_layer_count(sprite s)
{
    return sg_Sprites_SpriteLayerCount(s);
}

#ifdef __cplusplus

int32_t sprite_layer_height(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedHeight(s, name);
}

#endif

int32_t sprite_layer_named_height(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedHeight(s, name);
}

int32_t sprite_layer_height(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerHeight(s, idx);
}

int32_t sprite_layer_index(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerIndex(s, name);
}

void sprite_layer_name(sprite s, int32_t idx, char *result)
{
    sg_Sprites_SpriteLayerName(s, idx, result);
}

#ifdef __cplusplus

point2d sprite_layer_offset(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerOffsetNamed(s, name);
}

#endif

point2d sprite_layer_offset_named(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerOffsetNamed(s, name);
}

point2d sprite_layer_offset(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerOffset(s, idx);
}

void sprite_layer_offsets(sprite s, point2d *result, int32_t result_len)
{
    sg_Sprites_SpriteLayerOffsets(s, result, result_len);
}

#ifdef __cplusplus

rectangle sprite_layer_rectangle(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedRectangle(s, name);
}

#endif

rectangle sprite_layer_named_rectangle(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedRectangle(s, name);
}

rectangle sprite_layer_rectangle(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerRectangle(s, idx);
}

#ifdef __cplusplus

int32_t sprite_layer_width(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedWidth(s, name);
}

#endif

int32_t sprite_layer_named_width(sprite s, const char *name)
{
    return sg_Sprites_SpriteLayerNamedWidth(s, name);
}

int32_t sprite_layer_width(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteLayerWidth(s, idx);
}

void sprite_layers(sprite s, bitmap *result, int32_t result_len)
{
    sg_Sprites_SpriteLayers(s, result, result_len);
}

float sprite_mass(sprite s)
{
    return sg_Sprites_SpriteMass(s);
}

void sprite_name(sprite sprt, char *result)
{
    sg_Sprites_SpriteName(sprt, result);
}

sprite sprite_named(const char *name)
{
    return sg_Sprites_SpriteNamed(name);
}

bool sprite_offscreen(sprite s)
{
    return sg_Sprites_SpriteOffscreen(s) != 0;
}

#ifdef __cplusplus

bool sprite_on_screen_at(sprite s, const point2d &pt)
{
    return sg_Sprites_SpriteOnScreenAtPoint(s, &pt) != 0;
}

#endif

bool sprite_on_screen_at_point(sprite s, const point2d *pt)
{
    return sg_Sprites_SpriteOnScreenAtPoint(s, pt) != 0;
}

bool sprite_on_screen_at_point_byval(sprite s, const point2d pt)
{
    return sg_Sprites_SpriteOnScreenAtPoint(s, &pt) != 0;
}

bool sprite_on_screen_at(sprite s, int32_t x, int32_t y)
{
    return sg_Sprites_SpriteOnScreenAt(s, x, y) != 0;
}

point2d sprite_position(sprite s)
{
    return sg_Sprites_SpritePosition(s);
}

void sprite_replay_animation(sprite s)
{
    sg_Sprites_SpriteReplayAnimation(s);
}

#ifdef __cplusplus

void sprite_replay_animation(sprite s, bool withSound)
{
    sg_Sprites_ReplayAnimationWithSound(s, withSound != 0);
}

#endif

void replay_animation_with_sound(sprite s, bool withSound)
{
    sg_Sprites_ReplayAnimationWithSound(s, withSound != 0);
}

float sprite_rotation(sprite s)
{
    return sg_Sprites_SpriteRotation(s);
}

float sprite_scale(sprite s)
{
    return sg_Sprites_SpriteScale(s);
}

rectangle sprite_screen_rectangle(sprite s)
{
    return sg_Sprites_SpriteScreenRectangle(s);
}

void sprite_send_layer_backward(sprite s, int32_t visibleLayer)
{
    sg_Sprites_SpriteSendLayerBackward(s, visibleLayer);
}

void sprite_send_layer_to_back(sprite s, int32_t visibleLayer)
{
    sg_Sprites_SpriteSendLayerToBack(s, visibleLayer);
}

void sprite_set_collision_bitmap(sprite s, bitmap bmp)
{
    sg_Sprites_SpriteSetCollisionBitmap(s, bmp);
}

void sprite_set_collision_kind(sprite s, collision_test_kind value)
{
    sg_Sprites_SpriteSetCollisionKind(s, value);
}

void sprite_set_dx(sprite s, float value)
{
    sg_Sprites_SpriteSetDX(s, value);
}

void sprite_set_dy(sprite s, float value)
{
    sg_Sprites_SpriteSetDY(s, value);
}

void sprite_set_heading(sprite s, float value)
{
    sg_Sprites_SpriteSetHeading(s, value);
}

#ifdef __cplusplus

void sprite_set_layer_offset(sprite s, const char *name, const point2d &value)
{
    sg_Sprites_SpriteSetLayerOffsetNamed(s, name, &value);
}

#endif

void sprite_set_layer_offset_named(sprite s, const char *name, const point2d *value)
{
    sg_Sprites_SpriteSetLayerOffsetNamed(s, name, value);
}

void sprite_set_layer_offset_named_byval(sprite s, const char *name, const point2d value)
{
    sg_Sprites_SpriteSetLayerOffsetNamed(s, name, &value);
}

#ifdef __cplusplus

void sprite_set_layer_offset(sprite s, int32_t idx, const point2d &value)
{
    sg_Sprites_SpriteSetLayerOffset(s, idx, &value);
}

#endif

void sprite_set_layer_offset(sprite s, int32_t idx, const point2d *value)
{
    sg_Sprites_SpriteSetLayerOffset(s, idx, value);
}

void sprite_set_layer_offset_byval(sprite s, int32_t idx, const point2d value)
{
    sg_Sprites_SpriteSetLayerOffset(s, idx, &value);
}

void sprite_set_layer_offsets(sprite s, const point2d *values, int32_t values_len)
{
    sg_Sprites_SpriteSetLayerOffsets(s, values, values_len);
}

void sprite_set_mass(sprite s, float value)
{
    sg_Sprites_SpriteSetMass(s, value);
}

#ifdef __cplusplus

void sprite_set_position(sprite s, const point2d &value)
{
    sg_Sprites_SpriteSetPosition(s, &value);
}

#endif

void sprite_set_position(sprite s, const point2d *value)
{
    sg_Sprites_SpriteSetPosition(s, value);
}

void sprite_set_position_byval(sprite s, const point2d value)
{
    sg_Sprites_SpriteSetPosition(s, &value);
}

void sprite_set_rotation(sprite s, float value)
{
    sg_Sprites_SpriteSetRotation(s, value);
}

void sprite_set_scale(sprite s, float value)
{
    sg_Sprites_SpriteSetScale(s, value);
}

void sprite_set_speed(sprite s, float value)
{
    sg_Sprites_SpriteSetSpeed(s, value);
}

#ifdef __cplusplus

void sprite_set_value(sprite s, const char *name, float val)
{
    sg_Sprites_SpriteSetValueNamed(s, name, val);
}

#endif

void sprite_set_value_named(sprite s, const char *name, float val)
{
    sg_Sprites_SpriteSetValueNamed(s, name, val);
}

void sprite_set_value(sprite s, int32_t idx, float val)
{
    sg_Sprites_SpriteSetValue(s, idx, val);
}

#ifdef __cplusplus

void sprite_set_velocity(sprite s, const vector &value)
{
    sg_Sprites_SpriteSetVelocity(s, &value);
}

#endif

void sprite_set_velocity(sprite s, const vector *value)
{
    sg_Sprites_SpriteSetVelocity(s, value);
}

void sprite_set_velocity_byval(sprite s, const vector value)
{
    sg_Sprites_SpriteSetVelocity(s, &value);
}

void sprite_set_x(sprite s, float value)
{
    sg_Sprites_SpriteSetX(s, value);
}

void sprite_set_y(sprite s, float value)
{
    sg_Sprites_SpriteSetY(s, value);
}

int32_t sprite_show_layer(sprite s, int32_t id)
{
    return sg_Sprites_SpriteShowLayer(s, id);
}

#ifdef __cplusplus

int32_t sprite_show_layer(sprite s, const char *name)
{
    return sg_Sprites_SpriteShowLayerNamed(s, name);
}

#endif

int32_t sprite_show_layer_named(sprite s, const char *name)
{
    return sg_Sprites_SpriteShowLayerNamed(s, name);
}

float sprite_speed(sprite s)
{
    return sg_Sprites_SpriteSpeed(s);
}

void sprite_start_animation(sprite s, int32_t idx)
{
    sg_Sprites_SpriteStartAnimation(s, idx);
}

#ifdef __cplusplus

void sprite_start_animation(sprite s, const char *named)
{
    sg_Sprites_SpriteStartAnimationNamed(s, named);
}

#endif

void sprite_start_animation_named(sprite s, const char *named)
{
    sg_Sprites_SpriteStartAnimationNamed(s, named);
}

#ifdef __cplusplus

void sprite_start_animation(sprite s, const char *named, bool withSound)
{
    sg_Sprites_SpriteStartAnimationNamedWithSound(s, named, withSound != 0);
}

#endif

void sprite_start_animation_named_with_sound(sprite s, const char *named, bool withSound)
{
    sg_Sprites_SpriteStartAnimationNamedWithSound(s, named, withSound != 0);
}

#ifdef __cplusplus

void sprite_start_animation(sprite s, int32_t idx, bool withSound)
{
    sg_Sprites_SpriteStartAnimationWithSound(s, idx, withSound != 0);
}

#endif

void sprite_start_animation_with_sound(sprite s, int32_t idx, bool withSound)
{
    sg_Sprites_SpriteStartAnimationWithSound(s, idx, withSound != 0);
}

void sprite_toggle_layer_visible(sprite s, int32_t id)
{
    sg_Sprites_SpriteToggleLayerVisible(s, id);
}

#ifdef __cplusplus

void sprite_toggle_layer_visible(sprite s, const char *name)
{
    sg_Sprites_SpriteToggleLayerNamedVisible(s, name);
}

#endif

void sprite_toggle_layer_named_visible(sprite s, const char *name)
{
    sg_Sprites_SpriteToggleLayerNamedVisible(s, name);
}

float sprite_value(sprite s, int32_t index)
{
    return sg_Sprites_SpriteValue(s, index);
}

#ifdef __cplusplus

float sprite_value(sprite s, const char *name)
{
    return sg_Sprites_SpriteValueNamed(s, name);
}

#endif

float sprite_value_named(sprite s, const char *name)
{
    return sg_Sprites_SpriteValueNamed(s, name);
}

int32_t sprite_value_count(sprite s)
{
    return sg_Sprites_SpriteValueCount(s);
}

void sprite_value_names(sprite s, string_array result, int32_t result_len)
{
    sg_Sprites_SpriteValueNames(s, result, result_len);
}

vector sprite_velocity(sprite s)
{
    return sg_Sprites_SpriteVelocity(s);
}

int32_t sprite_visible_index_of_layer(sprite s, int32_t id)
{
    return sg_Sprites_SpriteVisibleIndexOfLayer(s, id);
}

#ifdef __cplusplus

int32_t sprite_visible_index_of_layer(sprite s, const char *name)
{
    return sg_Sprites_SpriteVisibleIndexOfLayerNamed(s, name);
}

#endif

int32_t sprite_visible_index_of_layer_named(sprite s, const char *name)
{
    return sg_Sprites_SpriteVisibleIndexOfLayerNamed(s, name);
}

int32_t sprite_visible_layer(sprite s, int32_t idx)
{
    return sg_Sprites_SpriteVisibleLayer(s, idx);
}

int32_t sprite_visible_layer_count(sprite s)
{
    return sg_Sprites_SpriteVisibleLayerCount(s);
}

void sprite_visible_layer_ids(sprite s, int32_t *result, int32_t result_len)
{
    sg_Sprites_SpriteVisibleLayerIds(s, result, result_len);
}

int32_t sprite_width(sprite s)
{
    return sg_Sprites_SpriteWidth(s);
}

float sprite_x(sprite s)
{
    return sg_Sprites_SpriteX(s);
}

float sprite_y(sprite s)
{
    return sg_Sprites_SpriteY(s);
}

void update_sprite(sprite s)
{
    sg_Sprites_UpdateSpritePctWithSound(s, 1.0, true != 0);
}

#ifdef __cplusplus

void update_sprite(sprite s, bool withSound)
{
    sg_Sprites_UpdateSpritePctWithSound(s, 1.0, withSound != 0);
}

#endif

void update_sprite_with_sound(sprite s, bool withSound)
{
    sg_Sprites_UpdateSpritePctWithSound(s, 1.0, withSound != 0);
}

#ifdef __cplusplus

void update_sprite(sprite s, float pct)
{
    sg_Sprites_UpdateSpritePctWithSound(s, pct, true != 0);
}

#endif

void update_sprite_percent(sprite s, float pct)
{
    sg_Sprites_UpdateSpritePctWithSound(s, pct, true != 0);
}

#ifdef __cplusplus

void update_sprite(sprite s, float pct, bool withSound)
{
    sg_Sprites_UpdateSpritePctWithSound(s, pct, withSound != 0);
}

#endif

void update_sprite_pct_with_sound(sprite s, float pct, bool withSound)
{
    sg_Sprites_UpdateSpritePctWithSound(s, pct, withSound != 0);
}

void update_sprite_animation(sprite s)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, 1.0, true != 0);
}

#ifdef __cplusplus

void update_sprite_animation(sprite s, float pct)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, pct, true != 0);
}

#endif

void update_sprite_animation_percent(sprite s, float pct)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, pct, true != 0);
}

#ifdef __cplusplus

void update_sprite_animation(sprite s, bool withSound)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, 1.0, withSound != 0);
}

#endif

void update_sprite_animation_with_sound(sprite s, bool withSound)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, 1.0, withSound != 0);
}

#ifdef __cplusplus

void update_sprite_animation(sprite s, float pct, bool withSound)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, pct, withSound != 0);
}

#endif

void update_sprite_animation_pct_with_sound(sprite s, float pct, bool withSound)
{
    sg_Sprites_UpdateSpriteAnimationPctWithSound(s, pct, withSound != 0);
}

#ifdef __cplusplus

vector vector_from_center_sprite_to_point(sprite s, const point2d &pt)
{
    return sg_Sprites_VectorFromCenterSpriteToPoint(s, &pt);
}

#endif

vector vector_from_center_sprite_to_point(sprite s, const point2d *pt)
{
    return sg_Sprites_VectorFromCenterSpriteToPoint(s, pt);
}

vector vector_from_center_sprite_to_point_byval(sprite s, const point2d pt)
{
    return sg_Sprites_VectorFromCenterSpriteToPoint(s, &pt);
}

vector vector_from_to(sprite s1, sprite s2)
{
    return sg_Sprites_VectorFromTo(s1, s2);
}

