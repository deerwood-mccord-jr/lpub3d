
/****************************************************************************
**
** Copyright (C) 2007-2009 Kevin Clague. All rights reserved.
** Copyright (C) 2015 - 2025 Trevor SANDY. All rights reserved.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef NAME_H
#define NAME_H

#include "QString"

#define LPUB3D_OPACITY_TO_ALPHA(o,a)(((o * a) + (100 - 1)) / 100)

class Gui;
extern Gui *gui;

class LDVWidget;
extern LDVWidget *ldvWidget;

struct ActionAttributes
{
    const char* ID;
    const char* MenuName;
    const char* StatusText;
};

struct StepLines {
  int top;
  int bottom;
  StepLines() : top(0), bottom(0) {}
  StepLines( int _top, int _bottom) :
      top(_top), bottom(_bottom) {}
  bool isInScope(int value)
  { return value >= top && value <= bottom; }
};

struct TypeLine {
  int modelIndex;
  int lineIndex;
  TypeLine() : modelIndex(-1), lineIndex(-1) {}
  TypeLine( int _modelIndex, int _lineIndex) :
      modelIndex(_modelIndex), lineIndex(_lineIndex) {}
};

enum LineHighlightType { HIGHLIGHT_NULL, HIGHLIGHT_CLEAR, HIGHLIGHT_SELECTION, HIGHLIGHT_CURRENT };
struct LineHighlight {
    int line;
    LineHighlightType action;
    LineHighlight() : line(0), action(HIGHLIGHT_NULL) {}
    LineHighlight(int _line, LineHighlightType _action) :
        line(_line), action(_action) {}
};

class QAction;
struct Action {
    QString id;
    QAction *action;
    Action() : action(nullptr) {}
    Action(const QString &_id, QAction *_action) :
        id(_id), action(_action) {}
};

struct LoadStatus {
    bool const isMpd;
    int const loadedLines;
    int const loadedSteps;
    int const subFileCount;
    int const partCount;
    int const uniquePartCount;
    int const helperPartCount;
    int const displayModelPartCount;
    QString const &modelFile;
    QString const &elapsedTime;
    QStringList const &loadedItems;
    LoadStatus(bool const _isMpd,
               int const _loadedLines,
               int const _loadedSteps,
               int const _subFileCount,
               int const _partCount,
               int const _uniquePartCount,
               int const _helperPartCount,
               int const _displayModelPartCount,
               QString const &_modelFile,
               QString const &_elapsedTime,
               QStringList const &_loadedItems)
        : isMpd(_isMpd)
        , loadedLines(_loadedLines)
        , loadedSteps(_loadedSteps)
        , subFileCount(_subFileCount)
        , partCount(_partCount)
        , uniquePartCount(_uniquePartCount)
        , helperPartCount(_helperPartCount)
        , displayModelPartCount(_displayModelPartCount)
        , modelFile(_modelFile)
        , elapsedTime(_elapsedTime)
        , loadedItems(_loadedItems)
    {}
};

enum RemoveLPubFormatType { RLPF_NONE = -1, RLPF_DOCUMENT, RLPF_SUBMODEL, RLPF_PAGE, RLPF_STEP, RLPF_CALLOUT, RLPF_BOM };
enum RendererType { RENDERER_INVALID = -1, RENDERER_NATIVE, RENDERER_LDVIEW, RENDERER_LDGLITE, RENDERER_POVRAY, RENDERER_BLENDER, NUM_RENDERERS };
enum PartType { FADE_PART, HIGHLIGHT_PART, NORMAL_PART, NUM_PART_TYPES };
enum PliType { PART, SUBMODEL, BOM, NUM_PLI_TYPES };
enum NativeRenderType { NATIVE_VIEW, NATIVE_IMAGE, NATIVE_EXPORT };
enum DividerType { StepDivider, RangeDivider, NoDivider };
enum ShowLoadMsgType { NEVER_SHOW, ALWAYS_SHOW, SHOW_MESSAGE, SHOW_WARNING, SHOW_ERROR };
enum MissingHeaderType { NoneMissing, NameMissing, AuthorMissing, BothMissing };
enum RulerTrackingType { TRACKING_TICK, TRACKING_LINE, TRACKING_NONE};
enum SceneGuidesPosType { GUIDES_TOP_LEFT, GUIDES_TOP_RIGHT, GUIDES_CENTRE, GUIDES_BOT_LEFT, GUIDES_BOT_RIGHT};
enum RemoveObjectsRc { RemovedPieceRc, RemovedCameraRc, RemovedLightRc };
enum LibType { LibLEGO, LibTENTE, LibVEXIQ, NumLibs };
enum ThemeType { ThemeDark, ThemeDefault };
enum SaveOnSenderType { SaveOnNone, SaveOnRedraw, SaveOnUpdate };
enum NativeType { NTypeDefault, NTypeCalledOut, NTypeMultiStep };
enum ShowLineType { PS_POS, LINE_HIGHLIGHT = PS_POS, PS_LAST_POS, LINE_ERROR = PS_LAST_POS, PS_STEP_NUM };
enum ProcessType { PROC_NONE, PROC_WRITE_TO_TMP, PROC_FIND_PAGE, PROC_DRAW_PAGE, PROC_DISPLAY_PAGE, PROC_COUNT_PAGE };
enum Dimensions {Pixels = 0, Inches };
enum PageActType { SET_DEFAULT_ACTION, SET_STOP_ACTION };
enum ExportOptionType { EXPORT_ALL_PAGES, EXPORT_PAGE_RANGE, EXPORT_CURRENT_PAGE };
enum RecentFilesType { MAX_RECENT_FILES = 8 };
enum RendererParamObjType { RPO_ASSEM, RPO_PLI, RPO_BOM, RPO_MODEL };
enum CyclePageDlgType { CycleNone = -1, CycleYes, CycleNo, CycleCancel };

enum SceneObjectInfo { ObjectId };
enum CamFlag { DefFoV, DefZNear, DefZFar };
enum IniFlag { NativePOVIni, NativeSTLIni, Native3DSIni, NativePartList, POVRayRender, LDViewPOVIni, LDViewIni, NumIniFiles };

enum LDrawFileRegExpType {
    SOF_RX,  // Start of File
    DAT_RX,  // Imbedded Image Data
    B64_RX,  // Base 64 Image Data Line
    EOF_RX,  // End of File
    LDR_RX,  // LDraw File
    DES_RX,  // Model Description
    NAM_RX,  // Name Header
    NAK_RX,  // Name Header Key
    AUT_RX,  // Author Header
    AUK_RX,  // Author Header Key
    CAT_RX,  // Category Header
    INC_RX,  // Include File
    LDG_RX,  // LDCad Group
    LDC_RX,  // LDCad Generated Content
    EOH_RX,  // End of Header
    DMS_RX,  // Display Model Step
    LDS_RX,  // LDraw Step boundry
    FHE_RX,  // Fade or Highlight Enabled (or Setup)
    LFH_RX   // LPub Fade or LPub Highlight
};

enum DisplayType { DT_DEFAULT,
                   DT_PAGE,
                   DT_LDV_FUNCTION = DT_PAGE,
                   DT_COVER_FRONT,
                   DT_COVER_BACK,
                   DT_MODEL_DEFAULT,
                   DT_MODEL_COVER_PAGE_PREVIEW,
                   DT_MODEL_DISPLAY,
                   DT_MODEL_FINAL
};

enum LogType { LOG_STATUS,
               LOG_INFO_STATUS,
               LOG_SHOW_DIALOG = LOG_INFO_STATUS,
               LOG_NOTICE,
               LOG_INFO,
               LOG_TRACE,
               LOG_DEBUG,
               LOG_WARNING,
               LOG_ERROR,
               LOG_FATAL
};
enum TraverseRc { HitNothing,
                  HitEndOfFile = HitNothing,
                  HitEndOfPage,
                  HitBuildModAction,
                  HitBottomOfStep,
                  HitEndOfSubmodel,
                  HitCsiAnnotation,
                  HitInvalidLDrawLine,
                  HitRangeError,
                  HitAbortProcess
};
enum LoadMsgType { VALID_LOAD_MSG,
                   INLINE_PART_LOAD_MSG,
                   INLINE_GENERATED_PART_LOAD_MSG,
                   INLINE_PRIMITIVE_LOAD_MSG,
                   INLINE_SUBPART_LOAD_MSG,
                   INLINE_DATA_LOAD_MSG,
                   MPD_SUBMODEL_LOAD_MSG,
                   LDR_SUBFILE_LOAD_MSG,
                   HELPER_PART_LOAD_MSG,
                   MISSING_PART_LOAD_MSG,
                   /* Do not add these into the load status dialogue because they are not loaded in the LDrawFile.subfiles
                   PRIMITIVE_LOAD_MSG,
                   SUBPART_LOAD_MSG,
                   */
                   EMPTY_SUBMODEL_LOAD_MSG,
                   BAD_DATA_LOAD_MSG,
                   BAD_INCLUDE_LOAD_MSG,
                   INCLUDE_FILE_LOAD_MSG,
                   ALL_LOAD_MSG
};
enum ActionModuleType { NO_ACTION,                 //  0
                        MAIN_WINDOW_ACTION,        //  1
                        COMMAND_EDITOR_ACTION,     //  2
                        TEXT_EDITOR_ACTION,        //  3
                        VISUAL_EDITOR_ACTION,      //  4
                        PARAMS_EDITOR_ACTION,      //  5
                        COMMANDS_DIALOG_ACTION,    //  6
                        COMMANDS_TEXT_EDIT_ACTION, //  7
                        OTHER_ACTION               //  8
};
enum PageDirection { PAGE_NO_DIRECTION,                 // 0
                     PAGE_DEFAULT  = PAGE_NO_DIRECTION, // 0
                     PAGE_NEXT,                         // 1
                     PAGE_FORWARD  = PAGE_NEXT,         // 1
                     PAGE_JUMP_FORWARD,                 // 2
                     PAGE_BACKWARD,                     // 3
                     PAGE_PREVIOUS = PAGE_BACKWARD,     // 3
                     PAGE_JUMP_BACKWARD                 // 4
};
enum ExportMode { ERROR_ENCOUNTERED = -3,  //-3 to pass error encountered to visual editor banner
                  PRINT_FILE   = -2,       //-2
                  EXPORT_NONE  = -1,       //-1
                  PAGE_PROCESS =  0,       // 0
                  EXPORT_PDF,              // 1
                  EXPORT_PNG,              // 2
                  EXPORT_JPG,              // 3
                  EXPORT_BMP,              // 4
                  EXPORT_3DS_MAX,          // 5
                  EXPORT_COLLADA,          // 6
                  EXPORT_WAVEFRONT,        // 7
                  EXPORT_STL,              // 8
                  EXPORT_POVRAY,           // 9
                  EXPORT_BRICKLINK,        // 10
                  EXPORT_CSV,              // 11
                  EXPORT_ELEMENT,          // 12 not implemented from console
                  EXPORT_HTML_PARTS,       // 13
                  EXPORT_HTML_STEPS,       // 14
                  EXPORT_LDRAW_MODEL,      // 15
                  POVRAY_RENDER,           // 16
                  BLENDER_RENDER,          // 17
                  BLENDER_IMPORT,          // 18
                  GENERATE_BOM             // 19
};
enum PartSource {
    EDITOR_CLR         = -2,               //  -2
    NOT_FOUND          = -1,               //  -1
    OUT_OF_BOUNDS      = NOT_FOUND,        //  -1
    NEW_PART           = NOT_FOUND,        //  -1
    NEW_MODEL          = NOT_FOUND,        //  -1
    EDITOR_LINE,                           //   0
    VIEWER_NONE        = EDITOR_LINE,      //   0
    VIEWER_LINE,                           //   1
    VIEWER_MOD,                            //   2
    VIEWER_DEL,                            //   3
    VIEWER_SEL,                            //   4
    VIEWER_CLR                             //   5
};
enum BuildModRc {
    BM_PREVIOUS_ACTION  = -4,
    BM_NEXT_ACTION      = -3,
    BM_LAST_ACTION      = -2,
    BM_NONE             = -1,
    BM_INVALID_INDEX    = BM_NONE,         //  -1
    BM_BEGIN,                              //   0 MOD LEVEL BEGIN
    BM_INIT             = BM_BEGIN,        //   0
    BM_NO_STEP          = BM_BEGIN,        //   0
    BM_BASE_LEVEL       = BM_BEGIN,        //   0
    BM_FIRST_INDEX      = BM_BEGIN,        //   0
    BM_MODEL_NAME       = BM_BEGIN,        //   0
    BM_STEP_MODEL_KEY   = BM_BEGIN,        //   0
    BM_BEGIN_LINE_NUM   = BM_BEGIN,        //   0 BUILD_MOD BEGIN   BuildModRange[0] Attributes[0]
    BM_ACTION_KEY_INDEX = BM_BEGIN,        //   0
    BM_END_MOD,                            //   1
    BM_FIRST_LEVEL      = BM_END_MOD,      //   1
    BM_STEP_LINE_KEY    = BM_END_MOD,      //   1
    BM_ACTION_LINE_NUM  = BM_END_MOD,      //   1 BUILD_MOD END_MOD BuildModRange[1] Attributes[1]
    BM_LINE_NUMBER      = BM_END_MOD,      //   1
    BM_END,                                //   2 MOD LEVEL END
    BM_END_LINE_NUM     = BM_END,          //   2 BUILD_MOD END                      Attributes[2]
    BM_STEP_NUM_KEY     = BM_END,          //   2
    BM_MODEL_INDEX      = BM_END,          //   2 MODEL_INDEX       BuildModRange[2]
    BM_ACTION_CODE      = BM_END,          //   2
    BM_STEP_KEYS,                          //   3
    BM_DISPLAY_PAGE_NUM = BM_STEP_KEYS,    //   3                                    Attributes[3]
    BM_STEP_PIECES,                        //   4                                    Attributes[4]
    BM_SUBMODEL_STACK   = BM_STEP_PIECES,  //   4
    BM_MODEL_NAME_INDEX,                   //   5                                    Attributes[5]
    BM_MODEL_LINE_NUM,                     //   6                                    Attributes[6]
    BM_MODEL_STEP_NUM,                     //   7                                    Attributes[7]
    BM_SINGLE_STEP,                        //   8
    BM_MULTI_STEP,                         //   9
    BM_CALLOUT_STEP,                       //  10
    BM_CHANGE,                             //  11
    BM_DELETE,                             //  12
    BM_CURRENT                             //  12
};
enum GridStepSize {
    GRID_SIZE_FIRST,
    SCENE_GRID_SIZE_S1 = GRID_SIZE_FIRST,
    SCENE_GRID_SIZE_S2,
    SCENE_GRID_SIZE_S3,
    SCENE_GRID_SIZE_S4,
    SCENE_GRID_SIZE_S5,
    SCENE_GRID_SIZE_S6,
    SCENE_GRID_SIZE_S7,
    SCENE_GRID_SIZE_S8,
    SCENE_GRID_SIZE_S9,
    NUM_GRID_SIZES,
    GRID_SIZE_LAST = NUM_GRID_SIZES
};
enum LDrawUnofficialFileType {
    UNOFFICIAL_UNKNOWN,
    UNOFFICIAL_SUBMODEL = UNOFFICIAL_UNKNOWN,
    UNOFFICIAL_PART,
    UNOFFICIAL_GENERATED_PART,
    UNOFFICIAL_SUBPART,
    UNOFFICIAL_PRIMITIVE,
    UNOFFICIAL_SHORTCUT,
    UNOFFICIAL_DATA,
    UNOFFICIAL_OTHER,
    UNOFFICIAL_NUM
};
enum SubAttributes {
    sAdj = -2,
    sType = 0,                 // 0  level 1   substitution
    sColorCode,                // 1  level 2   substitution
    sModelScale,               // 2  level 3   substitution
    sCameraFoV,                // 3  level 4   substitution
    sCameraAngleXX,            // 4  level 5   substitution
    sSubPart,                  // 5  elements in "0 !LPUB PLI BEGIN SUB <part type>"
    sCameraAngleYY = sSubPart, // 5  level 5   substitution
    sSubColor,                 // 6  elements in "0 !LPUB PLI BEGIN SUB <part type> <colorCode>"
    sTargetX = sSubColor,      // 6  level 6/8 substitution
    sTargetY,                  // 7  level 6/8 substitution
    sTargetZ,                  // 8  level 6/8 substitution
    sRotX,                     // 9  level 7/8 substitution
    sRotY,                     // 10 level 7/8 substitution
    sRotZ,                     // 11 level 7/8 substitution
    sTransform,                // 12 level 7/8 substitution
    sOriginalType,             // 13 Substituted part/Original LDraw part
    sSubstitute,               // 14
    sUpdate,                   // 15
    sRemove,                   // 16
    sRemoveAlt                 // 17
};
enum NameKeyAttributes {
    nType = 0,        // 0 Includes the Render index at end delimited by '-'. Set to CSI for CSI type
    nColorCode,       // 1 This is Step Number for CSI type
    nPageWidth,       // 2
    nResolution,      // 3
    nResType,         // 4
    nModelScale,      // 5
    nCameraFoV,       // 6
    nAdjustedBaseAttributes = nCameraFoV,   // 6th element index
    nCameraAngleXX,   // 7
    nCameraAngleYY,   // 8
    nBaseAttributes      = nCameraAngleYY,  // 8th element index
    nTargetX,         // 9
    nAdjustedTarget      = nTargetX,        // 9th element index
    nRotX                = nTargetX,        // 9th element index
    nTargetY,         // 10
    nRotY                = nTargetY,        // 10th element index
    nTargetZ,         // 11
    nRotZ                = nTargetZ,        // 11th element index
    nHasTarget,       // 12  Size of keys with Target
    nRot_X               = nHasTarget,      // 12th element index
    nRotTrans            = nHasTarget,
    nHasRotstep,      // 13  Size of keys with Rotstep
    nRot_Y               = nHasRotstep,     // 13th element index
    nRot_Z,           // 14
    nRot_Trans,       // 15
    nHasTargetAndRotstep// 16 Size of keys with Target and Rotstep
};
enum NameKeyAttributes2 {
    K_STEPNUMBER = 0, // 0  not used
    K_IMAGEWIDTH,     // 1  not used
    K_RESOLUTION,     // 2
    K_RESOLUTIONTYPE, // 3
    K_MODELSCALE,     // 4
    K_FOV,            // 5  not used
    K_LATITUDE,       // 6
    K_LONGITUDE,      // 7
    K_TARGETX,        // 8
    K_TARGETY,        // 9
    K_TARGETZ,        // 10
    K_ROTSX,          // 11
    K_ROTSY,          // 12
    K_ROTSZ,          // 13
    K_ROTSTYPE        // 14
};
/*
 * Scene Objects
 *
 * Purpose: Set ZValue
 *
 * Dependencies:
 * 1. name.h           - Define SceneObject static values - enum ZValue defines, IncludedSceneObjects[]
 * 2. lpub.cpp         - Define object map - void Gui::initialize() soMap
 * 3. Meta.h           - Define meta class - SceneItemMeta
 * 4. Meta.cpp         - Construct and initialize meta class - SceneItemMeta::SceneItemMeta(), SceneItemMeta::init()
 * 5. traverse.cpp     - Parse meta and set object position - case SceneItemZValueDirectionRc
 * 6. formatpage.cpp   - Set object ZValue - bool Gui::getSceneObject(()
 * 7. <BackgroundItem> - GraphicsItem - the entity the ZValue is set for
 */
enum SceneObject {
  //Object                     ID, //    GraphicsItem                  / Type Identifier
    UndefinedObj             = -1,
    AssemAnnotationObj       = 36, //  0 CsiAnnotationItem             / CsiAnnotationType
    AssemAnnotationPartObj   = 27, //  1 PlacementCsiPart              / CsiPartType
    AssemObj                 =  1, //  2 CsiItem                       / CsiType
    CalloutBackgroundObj     =  5, //  4 CalloutBackgroundItem         / CalloutType
    CalloutInstanceObj       =  8, //  5 CalloutInstanceItem           /
    CalloutPointerObj        =  9, //  6 CalloutPointerItem            /
    CalloutUnderpinningObj   = 10, //  7 UnderpinningsItem             /
    DividerBackgroundObj     = 11, //  8 DividerBackgroundItem         /
    DividerObj               = 12, //  9 DividerItem                   /
    DividerLineObj           = 13, // 10 DividerLine                   /
    DividerPointerObj        = 37, // 11 DividerPointerItem            / DividerPointerType
    PointerGrabberObj        = 14, // 12 Grabber                       /
    PliGrabberObj            = 41, // 13 Grabber                       /
    SubmodelGrabberObj       = 42, // 14 Grabber                       /
    InsertPixmapObj          = 15, // 15 InsertPixmapItem              /
    InsertTextObj            = 30, // 16 TextItem                      / TextType
    MultiStepBackgroundObj   =  2, // 17 MultiStepRangeBackgroundItem  / StepGroupType
    MultiStepsBackgroundObj  = 43, // 18 MultiStepRangesBackgroundItem /
    PageAttributePixmapObj   = 17, // 19 PageAttributePixmapItem       / PageDocumentLogoType, PageCoverImageType
    PageAttributeTextObj     = 19, // 20 PageAttributeTextItem         / PageTitleType ... PagePlugType
    PageBackgroundObj        =  0, // 21 PageBackgroundItem            / PageType
    PageNumberObj            =  6, // 22 PageNumberItem                / PageNumberType
    PagePointerObj           = 29, // 23 PagePointerItem               / PagePointerType
    PartsListAnnotationObj   = 20, // 24 AnnotateTextItem              /
    PartsListBackgroundObj   =  4, // 25 PliBackgroundItem             / PartsListType
    PartsListInstanceObj     = 21, // 26 InstanceTextItem              /
    PointerHeadObj           = 22, // 27 PointerHeadItem               /
    PointerFirstSegObj       = 23, // 28 BorderedLineItem              /
    PointerSecondSegObj      = 24, // 29 BorderedLineItem              /
    PointerThirdSegObj       = 28, // 30 BorderedLineItem              /
    RotateIconBackgroundObj  = 26, // 31 RotateIconItem                / RotateIconType
    ReserveBackgroundObj     = 35, // 32 ReserveBackgroundItem         / ReserveType
    StepNumberObj            =  3, // 33 StepNumberItem                / StepNumberType
    SubModelBackgroundObj    = 25, // 34 SubModelBackgroundItem        / SubModelType
    SubModelInstanceObj      = 16, // 35 SMInstanceTextItem            /
    SubmodelInstanceCountObj = 18, // 36 SubmodelInstanceCount         / SubmodelInstanceCountType
    PartsListPixmapObj       = 44, // 37 PGraphicsPixmapItem           /
    PartsListGroupObj        = 45, // 38 PartGroupItem                 /
    StepBackgroundObj        = 46  // 39 MultiStepStepBackgroundItem   / StepType
};

static const SceneObject IncludedSceneObjects[] =
{
    AssemAnnotationObj,
    AssemAnnotationPartObj,
    AssemObj,
    CalloutBackgroundObj,
    CalloutInstanceObj,
    CalloutPointerObj,
    CalloutUnderpinningObj,
    DividerBackgroundObj,
    DividerLineObj,
    DividerObj,
    DividerPointerObj,
    InsertPixmapObj,
    InsertTextObj,
    MultiStepBackgroundObj,
    MultiStepsBackgroundObj,
    PageAttributePixmapObj,
    PageAttributeTextObj,
    PageBackgroundObj,
    PageNumberObj,
    PagePointerObj,
    PartsListAnnotationObj,
    PartsListBackgroundObj,
    PartsListGroupObj,
    PartsListInstanceObj,
    PartsListPixmapObj,
    PliGrabberObj,
    PointerFirstSegObj,
    PointerGrabberObj,
    PointerHeadObj,
    PointerSecondSegObj,
    PointerThirdSegObj,
    RotateIconBackgroundObj,
    ReserveBackgroundObj,
    StepBackgroundObj,
    StepNumberObj,
    SubModelBackgroundObj,
    SubmodelGrabberObj,
    SubmodelInstanceCountObj,
    SubModelInstanceObj
};

// Exempted from detection - triggers invalid object
static const SceneObject ExemptSceneObjects[] =
{
    PageBackgroundObj,      //  0
    PointerFirstSegObj,     // 22
    PointerSecondSegObj,    // 24
    PointerThirdSegObj,     // 28

    PartsListPixmapObj,     // 44
    PartsListAnnotationObj, // 20
    PartsListInstanceObj    // 21
};

// Trigger scene guide on PliPartGroup object
static const SceneObject PliPartGroupSceneObjects[] =
{
    PartsListPixmapObj,     // 44
    PartsListAnnotationObj, // 20
    PartsListInstanceObj    // 21
};

const int GridSizeTable[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

extern ActionAttributes sgCommands[NUM_GRID_SIZES];

// Theme colours

enum ThemeColorType {
    // THEME_DEFAULT
    THEME_DEFAULT_SCENE_BACKGROUND_COLOR,                    // "#AEADAC"
    THEME_DEFAULT_GRID_PEN,                                  // "#1E1B18"
    THEME_DEFAULT_RULER_PEN,                                 // "#1E1B18"
    THEME_DEFAULT_RULER_TICK_PEN,                            // "#35322F"
    THEME_DEFAULT_RULER_TRACK_PEN,                           // "#00FF00"
    THEME_DEFAULT_GUIDE_PEN,                                 // "#AA0000"
    THEME_DEFAULT_TRANS_PAGE_BORDER,                         // "#535559"

    THEME_DEFAULT_PALETTE_LIGHT,                             // "#AEADAC"

    THEME_DEFAULT_VIEWER_BACKGROUND_COLOR,                   // "#FFFFFF"
    THEME_DEFAULT_VIEWER_GRADIENT_COLOR_TOP,                 // "#36485F"
    THEME_DEFAULT_VIEWER_GRADIENT_COLOR_BOTTOM,              // "#313437"
    THEME_DEFAULT_AXES_COLOR,                                // "#000000"
    THEME_DEFAULT_OVERLAY_COLOR,                             // "#000000"
    THEME_DEFAULT_MARQUEE_BORDER_COLOR,                      // "#4040FF"
    THEME_DEFAULT_MARQUEE_FILL_COLOR  ,                      // "#4040FF"
    THEME_DEFAULT_INACTIVE_VIEW_COLOR ,                      // "#454545"
    THEME_DEFAULT_ACTIVE_VIEW_COLOR,                         // "#FF0000"
    THEME_DEFAULT_GRID_STUD_COLOR,                           // "#404040"
    THEME_DEFAULT_GRID_LINE_COLOR,                           // "#000000"
    THEME_DEFAULT_TEXT_COLOR,                                // "#000000"
    THEME_DEFAULT_VIEW_SPHERE_COLOR,                         // "#FFFFFF"
    THEME_DEFAULT_VIEW_SPHERE_TEXT_COLOR,                    // "#646464"
    THEME_DEFAULT_VIEW_SPHERE_HLIGHT_COLOR,                  // "#FF0000"

    THEME_DEFAULT_OBJECT_SELECTED_COLOR,                     // "#E54C66"
    THEME_DEFAULT_OBJECT_FOCUSED_COLOR,                      // "#664CE5"
    THEME_DEFAULT_CAMERA_COLOR,                              // "#80CC80"
    THEME_DEFAULT_LIGHT_COLOR,                               // "#80CC80"
    THEME_DEFAULT_CONTROL_POINT_COLOR,                       // "#80CC80"
    THEME_DEFAULT_CONTROL_POINT_FOCUSED_COLOR,               // "#664CE5"
    THEME_DEFAULT_BM_OBJECT_SELECTED_COLOR,                  // "#79D879"

    THEME_DEFAULT_DECORATE_LDRAW_COMMENTS,                   // "#006325"
    THEME_DEFAULT_DECORATE_LDRAW_HEADER,                     // "#4F97BA"
    THEME_DEFAULT_DECORATE_LDRAW_BODY,                       // "#005AF6"
    THEME_DEFAULT_DECORATE_LPUB3D_LOCAL,                     // "#609CFF"
    THEME_DEFAULT_DECORATE_LPUB3D_GLOBAL,                    // "#57649B"

    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_1,                // "#816288"
    THEME_DEFAULT_DECORATE_LDRAW_COLOUR_CODE,                // "#F46105"
    THEME_DEFAULT_DECORATE_LDRAW_PART_POSITION,              // "#ED3D63"
    THEME_DEFAULT_DECORATE_LDRAW_PART_TRANSFORM_1,           // "#8BC3F6"
    THEME_DEFAULT_DECORATE_LDRAW_PART_TRANSFORM_2,           // "#51ACFF"
    THEME_DEFAULT_DECORATE_LDRAW_PART_TRANSFORM_3,           // "#2F86FF"
    THEME_DEFAULT_DECORATE_LDRAW_PART_FILE,                  // "#084575"
    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_2,                // "#7D5E18"
    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_3,                // "#999966"
    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_4,                // "#CC9900"
    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_5,                // "#CC6600"
    THEME_DEFAULT_DECORATE_LPUB3D_NUMBER,                    // "#FC9B14"
    THEME_DEFAULT_DECORATE_LPUB3D_HEX_NUMBER,                // "#B87620"
    THEME_DEFAULT_DECORATE_LPUB3D_PAGE_SIZE,                 // "#C15317"

    THEME_DEFAULT_DECORATE_LEOCAD,                           // "#14148C"
    THEME_DEFAULT_DECORATE_LSYNTH,                           // "#D882F6"
    THEME_DEFAULT_DECORATE_LDCAD,                            // "#FF9900"
    THEME_DEFAULT_DECORATE_MLCAD,                            // "#0079CF"
    THEME_DEFAULT_DECORATE_MLCAD_BODY,                       // "#9421A6"
    THEME_DEFAULT_DECORATE_LPUB3D_FALSE,                     // "#FF1818"
    THEME_DEFAULT_DECORATE_LPUB3D_TRUE,                      // "#008000"
    THEME_DEFAULT_DECORATE_LPUB3D,                           // "#CC5980"
    THEME_DEFAULT_DECORATE_LPUB3D_BODY,                      // "#AA0000"
    THEME_DEFAULT_DECORATE_LDRAW_HEADER_VALUE,               // "#545454"
    THEME_DEFAULT_DECORATE_LPUB3D_QUOTED_TEXT,               // "#231AFF"
    THEME_DEFAULT_DECORATE_LDRAW_LINE_TYPE_0_FIRST_CHARACTER,// "#000000"
    THEME_DEFAULT_DECORATE_LDCAD_GROUP_DEFINE,               // "#BD4900"

    THEME_DEFAULT_DECORATE_INI_FILE_COMMENT,                 // "#006325"
    THEME_DEFAULT_DECORATE_INI_FILE_HEADER,                  // "#14148C"
    THEME_DEFAULT_DECORATE_INI_FILE_EQUAL,                   // "#0057FF"
    THEME_DEFAULT_DECORATE_INI_FILE_VALUE,                   // "#B25A2F"

    THEME_DEFAULT_DECORATE_PARAMETER_FILE_PART_ID,           // "#084575"
    THEME_DEFAULT_DECORATE_PARAMETER_FILE_PART_CONTROL,      // "#9421A6"
    THEME_DEFAULT_DECORATE_PARAMETER_FILE_PART_DESCRIPTION,  // "#AA0000"

    THEME_DEFAULT_LINE_SELECT,                               // "#AA0000"
    THEME_DEFAULT_LINE_HIGHLIGHT,                            // "#CCCCFF"
    THEME_DEFAULT_LINE_ERROR,                                // "#FFCCCC"
    THEME_DEFAULT_LINE_HIGHLIGHT_EDITOR_SELECT,              // "#00FFFF"
    THEME_DEFAULT_LINE_HIGHLIGHT_VIEWER_SELECT,              // "#00FF00"

    // THEME_DARK
    THEME_DARK_SCENE_BACKGROUND_COLOR,                       // "#31363B"
    THEME_DARK_GRID_PEN,                                     // "#FFFFFF"
    THEME_DARK_RULER_PEN,                                    // "#FFFFFF"
    THEME_DARK_RULER_TICK_PEN,                               // "#EFF0F1"
    THEME_DARK_RULER_TRACK_PEN,                              // "#00FF00"
    THEME_DARK_GUIDE_PEN,                                    // "#AA0000"
    THEME_DARK_TRANS_PAGE_BORDER,                            // "#AEADAC"
    THEME_DARK_EDIT_MARGIN,                                  // "#ABB2B9"

    THEME_DARK_DECORATE_LDRAW_COMMENTS,                      // "#17C723"
    THEME_DARK_DECORATE_LDRAW_HEADER,                        // "#3C9CFB"
    THEME_DARK_DECORATE_LDRAW_BODY,                          // "#14AAFF"
    THEME_DARK_DECORATE_LPUB3D_LOCAL,                        // "#609CFF"
    THEME_DARK_DECORATE_LPUB3D_GLOBAL,                       // "#A0B2E2"

    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_1,                   // "#C2A4C0"
    THEME_DARK_DECORATE_LDRAW_COLOUR_CODE,                   // "#F46105"
    THEME_DARK_DECORATE_LDRAW_PART_POSITION,                 // "#46B5D1"
    THEME_DARK_DECORATE_LDRAW_PART_TRANSFORM_1,              // "#DDFFEF"
    THEME_DARK_DECORATE_LDRAW_PART_TRANSFORM_2,              // "#A2FFD2"
    THEME_DARK_DECORATE_LDRAW_PART_TRANSFORM_3,              // "#5CFFB0"
    THEME_DARK_DECORATE_LDRAW_PART_FILE,                     // "#C3F6FE"
    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_2,                   // "#7D5E18"
    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_3,                   // "#999966"
    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_4,                   // "#CC9900"
    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_5,                   // "#CC6600"
    THEME_DARK_DECORATE_LPUB3D_NUMBER,                       // "#FC9B14"
    THEME_DARK_DECORATE_LPUB3D_HEX_NUMBER,                   // "#B87620"
    THEME_DARK_DECORATE_LPUB3D_PAGE_SIZE,                    // "#C15317"

    THEME_DARK_DECORATE_LEOCAD,                              // "#0079CF"
    THEME_DARK_DECORATE_LSYNTH,                              // "#FF9900"
    THEME_DARK_DECORATE_LDCAD,                               // "#FF9900"
    THEME_DARK_DECORATE_MLCAD,                               // "#0079CF"
    THEME_DARK_DECORATE_MLCAD_BODY,                          // "#9421A6"
    THEME_DARK_DECORATE_LPUB3D_FALSE,                        // "#FF8080"
    THEME_DARK_DECORATE_LPUB3D_TRUE,                         // "#ADFF2F"
    THEME_DARK_DECORATE_LPUB3D,                              // "#F638DC"
    THEME_DARK_DECORATE_LPUB3D_BODY,                         // "#FF3366"
    THEME_DARK_DECORATE_LDRAW_HEADER_VALUE,                  // "#AEAEAE"
    THEME_DARK_DECORATE_LPUB3D_QUOTED_TEXT,                  // "#81D4FA"
    THEME_DARK_DECORATE_LDRAW_LINE_TYPE_0_FIRST_CHARACTER,   // "#FFFFFF"
    THEME_DARK_DECORATE_LDCAD_GROUP_DEFINE,                  // "#BD4900"

    THEME_DARK_DECORATE_INI_FILE_COMMENT,                    // "#17C723"
    THEME_DARK_DECORATE_INI_FILE_HEADER,                     // "#0079CF"
    THEME_DARK_DECORATE_INI_FILE_EQUAL,                      // "#FF5227"
    THEME_DARK_DECORATE_INI_FILE_VALUE,                      // "#BBBFFF"

    THEME_DARK_DECORATE_PARAMETER_FILE_PART_ID,              // "#C3F6FE"
    THEME_DARK_DECORATE_PARAMETER_FILE_PART_CONTROL,         // "#9421A6"
    THEME_DARK_DECORATE_PARAMETER_FILE_PART_DESCRIPTION,     // "#AA0000"

    THEME_DARK_LINE_SELECT,                                  // "#E8E8E8"
    THEME_DARK_LINE_HIGHLIGHT,                               // "#5D5B59"
    THEME_DARK_LINE_ERROR,                                   // "#FF0000"
    THEME_DARK_LINE_HIGHLIGHT_EDITOR_SELECT,                 // "#00FFFF"
    THEME_DARK_LINE_HIGHLIGHT_VIEWER_SELECT,                 // "#00FF00"

    THEME_DARK_PALETTE_WINDOW,                               // "#313437"
    THEME_DARK_PALETTE_WINDOW_TEXT,                          // "#F0F0F0"
    THEME_DARK_PALETTE_BASE,                                 // "#232629"
    THEME_DARK_PALETTE_ALT_BASE,                             // "#2C2F32"
    THEME_DARK_PALETTE_TIP_BASE,                             // "#E0E0F4"
    THEME_DARK_PALETTE_TIP_TEXT,                             // "#3A3A3A"

    THEME_DARK_PALETTE_PHOLDER_TEXT,                         // "#646464"

    THEME_DARK_PALETTE_TEXT,                                 // "#E0E0E0"
    THEME_DARK_PALETTE_BUTTON,                               // "#2D3033"
    THEME_DARK_PALETTE_BUTTON_TEXT,                          // "#E0E0F4"
    THEME_DARK_PALETTE_LIGHT,                                // "#414141"
    THEME_DARK_PALETTE_MIDLIGHT,                             // "#3E3E3E"
    THEME_DARK_PALETTE_DARK,                                 // "#232323"
    THEME_DARK_PALETTE_MID,                                  // "#323232"
    THEME_DARK_PALETTE_SHADOW,                               // "#141414"
    THEME_DARK_PALETTE_HILIGHT,                              // "#2980B9"
    THEME_DARK_PALETTE_HILIGHT_TEXT,                         // "#E8E8E8"
    THEME_DARK_PALETTE_LINK,                                 // "#2980B9"
    THEME_DARK_PALETTE_DISABLED_TEXT,                        // "#808080"

    THEME_DARK_VIEWER_BACKGROUND_COLOR,                      // "#313437"
    THEME_DARK_VIEWER_GRADIENT_COLOR_TOP,                    // "#0000BF"
    THEME_DARK_VIEWER_GRADIENT_COLOR_BOTTOM,                 // "#FFFFFF"
    THEME_DARK_AXES_COLOR,                                   // "#A0A0A0"
    THEME_DARK_OVERLAY_COLOR,                                // "#000000"
    THEME_DARK_MARQUEE_BORDER_COLOR,                         // "#4040FF"
    THEME_DARK_MARQUEE_FILL_COLOR  ,                         // "#4040FF"
    THEME_DARK_INACTIVE_VIEW_COLOR ,                         // "#454545"
    THEME_DARK_ACTIVE_VIEW_COLOR,                            // "#2980B9"
    THEME_DARK_GRID_STUD_COLOR,                              // "#181818"
    THEME_DARK_GRID_LINE_COLOR,                              // "#181818"
    THEME_DARK_TEXT_COLOR,                                   // "#A0A0A0"
    THEME_DARK_VIEW_SPHERE_COLOR,                            // "#232629"
    THEME_DARK_VIEW_SPHERE_TEXT_COLOR,                       // "#E0E0E0"
    THEME_DARK_VIEW_SPHERE_HLIGHT_COLOR,                     // "#2980B9"

    THEME_DARK_OBJECT_SELECTED_COLOR,                        // "#E54C66"
    THEME_DARK_OBJECT_FOCUSED_COLOR,                         // "#664CE5"
    THEME_DARK_CAMERA_COLOR,                                 // "#80CC80"
    THEME_DARK_LIGHT_COLOR,                                  // "#80CC80"
    THEME_DARK_CONTROL_POINT_COLOR,                          // "#80CC80"
    THEME_DARK_CONTROL_POINT_FOCUSED_COLOR,                  // "#664CE5"
    THEME_DARK_BM_OBJECT_SELECTED_COLOR,                     // "#79D879"

    THEME_DARK_GRAPHICSVIEW_BORDER_COLOR,                    // "#999999"
    THEME_NUM_COLORS                                         // 162
};

// Color picker: https://www.w3schools.com/colors/colors_picker.asp

#define LPUB3D_DEFAULT_COLOUR                  "#aa0000" // 170,   0,   0, 255 LPub3D Maroon

#define LPUB3D_DISABLED_TEXT_COLOUR            "#808080" // 128, 128, 128, 255

#define SPLASH_FONT_COLOUR                      LPUB3D_DEFAULT_COLOUR

#define THEME_DEFAULT                          "Default" // Default Theme

#define THEME_DARK                             "Dark"    // Dark Theme

#define THEME_SYSTEM                           "System"  // System Theme

#define Z_VALUE_DEFAULT                            0.0
#define GRABBER_ZVALUE_DEFAULT                     100.0
#define POINTER_ZVALUE_DEFAULT                    -1.0
#define ASSEM_ZVALUE_DEFAULT                       Z_VALUE_DEFAULT
#define ASSEMANNOTATION_ZVALUE_DEFAULT             Z_VALUE_DEFAULT
#define ASSEMANNOTATIONPART_ZVALUE_DEFAULT         Z_VALUE_DEFAULT
#define CALLOUTBACKGROUND_ZVALUE_DEFAULT          98.0
#define CALLOUTINSTANCE_ZVALUE_DEFAULT          1000.0
#define CALLOUTPOINTER_ZVALUE_DEFAULT             POINTER_ZVALUE_DEFAULT
#define CALLOUTUNDERPINNING_ZVALUE_DEFAULT        97.0
#define DIVIDER_ZVALUE_DEFAULT                   100.0
#define DIVIDERLINE_ZVALUE_DEFAULT                99.0
#define DIVIDERBACKGROUND_ZVALUE_DEFAULT          98
#define DIVIDERPOINTER_ZVALUE_DEFAULT              POINTER_ZVALUE_DEFAULT
#define INSERTPIXMAP_ZVALUE_DEFAULT              500.0
#define INSERTTEXT_ZVALUE_DEFAULT               1000.0
#define MULTISTEPBACKGROUND_ZVALUE_DEFAULT        -2.0
#define MULTISTEPSBACKGROUND_ZVALUE_DEFAULT       -2.0
#define PAGEATTRIBUTETEXT_ZVALUE_DEFAULT           1.0
#define PAGEATTRIBUTEPIXMAP_ZVALUE_DEFAULT         Z_VALUE_DEFAULT
#define PAGEBACKGROUND_ZVALUE_DEFAULT             -3.0
#define PAGENUMBER_ZVALUE_DEFAULT                  Z_VALUE_DEFAULT
#define PAGEPOINTER_ZVALUE_DEFAULT                 POINTER_ZVALUE_DEFAULT
#define PAGEPOINTERBACKGROUND_ZVALUE_DEFAULT       Z_VALUE_DEFAULT
#define PARTSLISTANNOTATION_ZVALUE_DEFAULT         Z_VALUE_DEFAULT
#define PARTSLISTBACKGROUND_ZVALUE_DEFAULT         Z_VALUE_DEFAULT
#define PARTSLISTINSTANCE_ZVALUE_DEFAULT           Z_VALUE_DEFAULT
#define PARTSLISTPARTGROUP_ZVALUE_DEFAULT          Z_VALUE_DEFAULT
#define PARTSLISTPARTPIXMAP_ZVALUE_DEFAULT         Z_VALUE_DEFAULT
#define PLIGRABBER_ZVALUE_DEFAULT                  GRABBER_ZVALUE_DEFAULT
#define POINTERGRABBER_ZVALUE_DEFAULT              GRABBER_ZVALUE_DEFAULT
#define POINTERFIRSTSEG_ZVALUE_DEFAULT            -2.0
#define POINTERSECONDSEG_ZVALUE_DEFAULT           -3.0
#define POINTERTHIRDSEG_ZVALUE_DEFAULT            -4.0
#define POINTERHEAD_ZVALUE_DEFAULT                -5.0
#define ROTATEICONBACKGROUND_ZVALUE_DEFAULT      101.0
#define RESERVE_BACKGROUND_ZVALUE_DEFAULT          Z_VALUE_DEFAULT
#define STEP_BACKGROUND_ZVALUE_DEFAULT             Z_VALUE_DEFAULT
#define STEPNUMBER_ZVALUE_DEFAULT                  Z_VALUE_DEFAULT
#define SUBMODELBACKGROUND_ZVALUE_DEFAULT          Z_VALUE_DEFAULT
#define SUBMODELGRABBER_ZVALUE_DEFAULT             GRABBER_ZVALUE_DEFAULT
#define SUBMODELINSTANCE_ZVALUE_DEFAULT            Z_VALUE_DEFAULT
#define SUBMODELINSTANCECOUNT_ZVALUE_DEFAULT       Z_VALUE_DEFAULT

#define GLOBAL_META_RX                              "^\\s*0\\s+!LPUB\\s+.*GLOBAL"

// registry sections
#define DEFAULTS                               "Defaults"
#define POVRAY                                 "POVRay"
#define SETTINGS                               "Settings"
#define MESSAGES                               "Messages"
#define MAINWINDOW                             "MainWindow"
#define PARMSWINDOW                            "ParmsWindow"
#define EDITWINDOW                             "EditWindow"
#define VISUALEDITWINDOW                       "VisualEditorWindow"
#define COMMANDSWINDOW                         "CommandsWindow"
#define FINDREPLACEWINDOW                      "FindReplaceWindow"
#define UPDATES                                "Updates"
#define LOGGING                                "Logging"
#define IMPORTLDRAW                            "ImportLDraw"
#define IMPORTLDRAWMM                          "ImportLDrawMM"
#define THEMECOLORS                            "ThemeColors"
#define KEYBOARDSHORTCUTS                      "KeyboardShortcuts"
#define TABLAYOUTS                             "TabLayouts"
#define RESTART                                "Restart"

#define BLENDER_RENDER_ADDON_FOLDER            "io_scene_render_ldraw"

#define MAX_TABLAYOUTS                         10

#define FADE_SFX                                "-fade"
#define HIGHLIGHT_SFX                           "-highlight"
#define RESTART_NOTICE                          "@@ReStArT@@"
#define RESTART_APPLICATION_KEY                 "RestartApplication"
#define LAST_DISPLAYED_PAGE_NUM_KEY             "LastDisplayedPageNum"
#define SAVE_SKIP_PARTS_ARCHIVE_KEY             "SaveSkipPartsArchive"
#define VIEW_IMPORT_TOOLBAR_KEY                 "ViewImportToolbar"
#define VIEW_EXPORT_TOOLBAR_KEY                 "ViewExportToolbar"
#define VIEW_LOAD_STATUS_TOOLBAR_KEY            "LoadStatusToolbar"
#define VIEW_CACHE_TOOLBAR_KEY                  "ViewCacheToolbar"
#define VIEW_SETUP_TOOLBAR_KEY                  "ViewSetupToolbar"
#define VIEW_EDIT_TOOLBAR_KEY                   "ViewEditToolbar"
#define VIEW_REMOVE_LPUB_FORMAT_TOOLBAR_KEY     "ViewRemoveLPubFormatToolBar"
#define VIEW_EDITPARAMS_TOOLBAR_KEY             "ViewEditParamsToolbar"

#define CASE_CHECK                              "CaseCheck"
#define WORD_CHECK                              "WordCheck"
#define REGEXP_CHECK                            "RegExpCheck"
#define DEFAULT                                 0
#define NEXT                                    1
#define PREVIOUS                                2

#define DEFAULT_EDITOR_FONT_WINDOWS             "MS Shell Dlg 2"
#define DEFAULT_EDITOR_FONT_MACOS               "San Francisco"
#define DEFAULT_EDITOR_FONT_LINUX               "Helvetica"
#define DEFAULT_EDITOR_FONT_SIZE_WINDOWS        8
#define DEFAULT_EDITOR_FONT_SIZE_MACOS          10
#define DEFAULT_EDITOR_FONT_SIZE_LINUX          9
#define DEFAULT_MARGIN                          0.05f
#define DEFAULT_MARGINS                         DEFAULT_MARGIN,DEFAULT_MARGIN
#define DEFAULT_MARGIN_RANGE                    0.0f,100.0f
#define DEFAULT_ROUND_RADIUS                    15.0f
#define DEFAULT_BORDER_THICKNESS                1.0f/64.0f                                        // 0.01562
#define DEFAULT_LINE_THICKNESS                  1.0f/32.0f                                        // 0.03125
#define DEFAULT_POINTER_THICKNESS               DEFAULT_LINE_THICKNESS + DEFAULT_BORDER_THICKNESS // 0.04687
#define DEFAULT_TIP_RATIO                       2.5f                                              // Width to Height ratio
#define DEFAULT_TIP_HEIGHT                      1.0f/8.0f                                         // 0.12500
#define DEFAULT_TIP_WIDTH                       DEFAULT_TIP_HEIGHT * DEFAULT_TIP_RATIO            // 0.31250
#define DEFAULT_MSG_BOX_MIN_WIDTH               300

#define RENDER_DEFAULT_WIDTH                    1280
#define RENDER_DEFAULT_HEIGHT                    720

#define DEFAULT_ASSEM_CAMERA_LATITUDE           23
#define DEFAULT_ASSEM_CAMERA_LONGITUDE          45
#define DEFAULT_PART_CAMERA_LATITUDE            23
#define DEFAULT_PART_CAMERA_LONGITUDE          -45
#define DEFAULT_SUBMODEL_CAMERA_LATITUDE        23
#define DEFAULT_SUBMODEL_CAMERA_LONGITUDE      -45

#define DEFAULT_LOG_LEVEL                       true

#define DEFAULT_BLENDER_IMPORT_MODULE           "TN"

#define DEFAULT_SUBMODEL_COLOR_01               "#FFFFFF"
#define DEFAULT_SUBMODEL_COLOR_02               "#FFFFCC"
#define DEFAULT_SUBMODEL_COLOR_03               "#FFCCCC"
#define DEFAULT_SUBMODEL_COLOR_04               "#CCCCFF"

#define HIGH_CONTRAST_STUD_CYLINDER_DEFAULT     "27,42,52,255"
#define HIGH_CONTRAST_PART_EDGE_DEFAULT         "0,0,0,255"
#define HIGH_CONTRAST_BLACK_EDGE_DEFAULT        "255,255,255,255"
#define HIGH_CONTRAST_DARK_EDGE_DEFAULT         "27,42,52,255"
#define LIGHT_DARK_INDEX_DEFAULT                0.5f
#define EDGE_COLOR_CONTRAST_DEFAULT             0.5f

#define RENDER_IMAGE_MAX_SIZE                   32768 // pixels
#define PLACEHOLDER_IMAGE_WIDTH                 68    // pixels
#define PLACEHOLDER_IMAGE_HEIGHT                79

#define STYLE_SIZE_DEFAULT                      0.28f // annotation style width, height, diameter in inches

#define GRID_SIZE_INDEX_DEFAULT                 1 // 20

#define GHOST_META                              "0 GHOST"

#define MAX_NUM_POV_GEN_ARGS (128)

#define DOT_PATH_DEFAULT                        "."
#define EMPTY_STRING_DEFAULT                    ""

#define LOGGING_LEVEL_DEFAULT                   "STATUS"

#define UNIX_SHELL                              "/bin/sh"
#define WINDOWS_SHELL                           "cmd.exe"
#define LINUX_SYS_EDITOR                        "gedit"
#define MACOS_SYS_EDITOR                        "textedit"
#define WINDOWS_SYS_EDITOR                      "notepad.exe"
#define WINDOWS_NPP                             "Program Files (x86)\\Notepad++\\notepad++.exe"
#define WINDOWS_NPP_X64                         "Program Files\\Notepad++\\notepad++.exe"
#define WINDOWS_NPP_LPUB3D_UDL_ARG              "-udl=LPUB3D"

#define LIBXQUARTZ_MACOS_VERSION                "11.0"   // base 11.0
#define LIBPNG_MACOS_VERSION                    "1.6.37" // base 1.6.34
#define LIBGL2PS_MACOS_VERSION                  "1.4.0"  // base 1.3.5
#define LIBJPEG_MACOS_VERSION                   "9c"     // base 8b
#define LIBXML_MACOS_VERSION                    "2.6.2"  // base 2.5.2
#define LIBMINIZIP_MACOS_VERSION                "1.2.11" // base 1.1.0

#define LIBTIFF_MACOS_VERSION                   "4.0.10" // base 3.6.1
#define LIBSDL_MACOS_VERSION                    "2.0.10" // base 2.0.2
#define LIBOPENEXR_MACOS_VERSION                "2.3.0"  // base 2.2.0
#define LIBILMBASE_MACOS_VERSION                "2.3.0"  // base 2.2.1

#define CAMERA_FOV_LDVIEW_P_DEFAULT              0.007f  // LPub3D (LDView) default [Mimic Perspective]
#define CAMERA_FOV_LDVIEW_P_MAX_DEFAULT         90.0f    // LPub3D (LDView) default

#define CAMERA_FOV_DEFAULT                       0.01f   // LPub3D (L3P) default [Orthographic]
#define CAMERA_FOV_NATIVE_DEFAULT               30.0F
#define CAMERA_FOV_MIN_DEFAULT                   0.0f    // LPub3D (L3P) default
#define CAMERA_FOV_MAX_DEFAULT                 360.0f    // LPub3D (L3P) default

#define CAMERA_FOV_NATIVE_MIN_DEFAULT            1.0f    // Native (LeoCAD) default
#define CAMERA_FOV_NATIVE_MAX_DEFAULT          359.0f    // Native (LeoCAD) default

#define CAMERA_ZNEAR_DEFAULT                    10.0f    // LPub3D (L3P) default
#define CAMERA_ZFAR_DEFAULT                   4000.0f    // LPub3D (L3P) default

#define CAMERA_DISTANCE_FACTOR_NATIVE_DEFAULT    8.0f    // LPub3D (LeoCAD) default
#define CAMERA_ZNEAR_NATIVE_DEFAULT             25.0f    // LPub3D (LeoCAD) default
#define CAMERA_ZFAR_NATIVE_DEFAULT           50000.0f    // LPub3D (LeoCAD) default

#define UPDATE_CHECK_FREQUENCY_DEFAULT          0        //0=Never,1=Daily,2=Weekly,3=Monthly

#define PAGE_HEIGHT_DEFAULT                     800
#define PAGE_WIDTH_DEFAULT                      600
#define LINE_WRAP_WIDTH                         160      //Text browser line width (change log)

#define STEP_SPACING_DEFAULT                    0.05f    // Step group step default spacing when center justified

#define PLAINTEXT_CHANGE_LOG_CUTOFF_VERSION    "2.2.2"   // last version of LPub3D to use html change notes

#define DURAT_LGEO_STL_LIB_INFO                 "LGEO Stereolithography (STL) library is available"

#define BUILD_MOD_APPLY                         "APPLY"
#define BUILD_MOD_REMOVE                        "REMOVE"
#define BUILD_MOD_BEGIN                         "BEGIN"

#define VISUAL_BANNER_SUFFIX                    "Visual Banner"
#define SUBMODEL_IMAGE_BASENAME                 "smi"
#define SUBMODEL_COVER_PAGE_PREVIEW_BASENAME    "coverpagepreview"
#define PREVIEW_MODEL_DEFAULT                   "Preview.ldr"
#define VIEWER_MODEL_DEFAULT                    "Model.ldr"

#define LEGO_LIBRARY                            "LEGO"
#define TENTE_LIBRARY                           "TENTE"
#define VEXIQ_LIBRARY                           "VEXIQ"

#define LEGO_SEARCH_DIR_KEY                     "LEGOLDSearchDirs"
#define TENTE_SEARCH_DIR_KEY                    "TENTELDSearchDirs"
#define VEXIQ_SEARCH_DIR_KEY                    "VEXIQLDSearchDirs"

#define LEGO_FADE_COLOUR_KEY                    "LEGOFadeStepColour"
#define TENTE_FADE_COLOUR_KEY                   "TENTEFadeStepColour"
#define VEXIQ_FADE_COLOUR_KEY                   "VEXIQFadeStepColour"

#define LEGO_LDRAW_LIB_PATH_KEY                 "LEGOLDrawLibPath"
#define TENTE_LDRAW_LIB_PATH_KEY                "TENTELDrawLibPath"
#define VEXIQ_LDRAW_LIB_PATH_KEY                "VEXIQLDrawLibPath"

#define LPUB3D_DATA_PATH_KEY                    "LPub3DDataPath"
#define LPUB3D_RECENT_FILES_KEY                 "LPRecentFileList"

#define LEGO_FADE_COLOUR_DEFAULT                "Light_Blue"
#define TENTE_FADE_COLOUR_DEFAULT               "Light_Orange"
#define VEXIQ_FADE_COLOUR_DEFAULT               "VEX_Sky_Blue"

#define LP3D_MAX_IMAGE_RENDER_PATH            256

#define NATIVE_IMAGE_CAMERA_FOV_ADJUST         15    // Native camera fov adjustment for image generation

#define POVRAY_RENDER_QUALITY_DEFAULT           0    // 0=High, 1-Medium, 2=Low
#define RENDERER_TIMEOUT_DEFAULT                6    // measured in seconds

#define PAGE_CYCLE_DISPLAY_DEFAULT              1    // measured in seconds
#define PAGE_DISPLAY_PAUSE_DEFAULT              3    // measured in seconds
#define MAX_OPEN_WITH_PROGRAMS_DEFAULT          3    // maximum open with programs entries
#define MESSAGE_LINE_WIDTH_DEFAULT             80    // default width of message line in characters
// Internal common material colours
#define LDRAW_EDGE_MATERIAL_COLOUR             "24"
#define LDRAW_MAIN_MATERIAL_COLOUR             "16"
#define LDRAW_MATERIAL_COLOUR                   16

#define FADE_OPACITY_DEFAULT                    50         // 50 percent transparency

#define SUBMODEL_ICON_INDEX_BASE                1000
#define LPUB3D_COLOUR_FADE_SUFFIX               "fade"
#define LPUB3D_COLOUR_FADE_PREFIX               "100"
#define LPUB3D_COLOUR_HIGHLIGHT_SUFFIX          "highlight"
#define LPUB3D_COLOUR_HIGHLIGHT_PREFIX          "110"
#define LPUB3D_COLOUR_FADE_NAME_PREFIX          "LPub3D_Fade_"
#define LPUB3D_COLOUR_HIGHLIGHT_NAME_PREFIX     "LPub3D_Highlight_"
#define LPUB3D_COLOUR_FILE_PREFIX               "colours_" //Not used

#define LPUB3D_IM_BASE_LDR_EXT                  "base.ldr"    // Image Matte LDraw working file extension
#define LPUB3D_IM_OVERLAY_LDR_EXT               "overlay.ldr" // Image Matte LDraw working file extension
#define LPUB3D_IM_BASE_PNG_EXT                  "base.png"    // Image Matte Png working file extension
#define LPUB3D_IM_OVERLAY_PNG_EXT               "overlay.png" // Image Matte Png working file extension
#define LPUB3D_MESSAGE_ICON                     ":/icons/lpub96.png"

#define HIGHLIGHT_COLOUR_DEFAULT                "#C0FFFF00"   // Bright Yellow (alpha 192 - hex CO)
#define HIGHLIGHT_LINE_WIDTH_DEFAULT            1             // line width 1 - 5

#define SCENE_GUIDES_LINE_DEFAULT               2             // PenStyle - DashLine

#define PUBLISH_DESCRIPTION_DEFAULT             "LDraw model"

#define COUNT_PAGE_PREFIX                       "count~page"

#define EDITOR_MIN_LINES_DEFAULT                300           // minimum number of lines to capture at each data read
#define EDITOR_MAX_LINES_DEFAULT                10000         // maximum number of lines to capture at each data read
#define EDITOR_DECORATION_DEFAULT               1             // 0 = simple, 1 = fancy

#define MPD_COMBO_MIN_ITEMS_DEFAULT             25
#define GO_TO_PAGE_MIN_ITEMS_DEFAULT            10
#define FILE_LOAD_WAIT_TIME                     300000        // 5 minutes
#define EDITOR_FILTER_MIN_WORD_LENGTH           3             // filter words in document that are greater than 3 characters

#endif // DECLARATIONS_H
