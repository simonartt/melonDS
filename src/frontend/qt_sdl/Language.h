/*
    melonDS - Chinese localization + Boss Key support

    This file is part of melonDS.
    melonDS is free software under the GNU General Public License v3.
*/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <QHash>

namespace Language
{

// Set by main.cpp on startup, updated when user changes settings
inline bool isChinese = false;

static QHash<QString, QString> zhCN;

static void InitTranslations()
{
    if (!zhCN.isEmpty()) return;

    // Menu bar
    zhCN["File"] = "文件(&F)";
    zhCN["System"] = "系统(&S)";
    zhCN["View"] = "显示(&V)";
    zhCN["Config"] = "设置(&C)";
    zhCN["Help"] = "帮助(&H)";

    // File menu
    zhCN["Open ROM..."] = "打开 ROM...";
    zhCN["Open ROM inside archive..."] = "打开压缩包内的 ROM...";
    zhCN["Open recent"] = "最近文件";
    zhCN["Boot firmware"] = "启动固件";
    zhCN["Launch DS menu"] = "启动 DS 菜单";
    zhCN["Insert cart..."] = "插入卡带...";
    zhCN["Eject cart"] = "弹出卡带";
    zhCN["Insert ROM cart..."] = "插入 ROM 卡带...";
    zhCN["Insert add-on cart"] = "插入扩展卡";
    zhCN["Import savefile"] = "导入存档";
    zhCN["Save state"] = "保存即时存档";
    zhCN["Load state"] = "加载即时存档";
    zhCN["File..."] = "文件...";
    zhCN["Undo state load"] = "撤销加载";
    zhCN["Open melonDS directory"] = "打开 melonDS 目录";
    zhCN["Quit"] = "退出";
    zhCN["Clear list"] = "清除列表";

    // System menu
    zhCN["Pause"] = "暂停";
    zhCN["Reset"] = "重置";
    zhCN["Stop"] = "停止";
    zhCN["Frame step"] = "单帧执行";
    zhCN["Power management"] = "电源管理";
    zhCN["Date and time"] = "日期和时间";
    zhCN["Enable cheats"] = "启用金手指";
    zhCN["Setup cheat codes"] = "设置金手指代码";
    zhCN["ROM info"] = "ROM 信息";
    zhCN["RAM search"] = "RAM 搜索";
    zhCN["Manage DSi titles"] = "管理 DSi 标题";

    // Multiplayer
    zhCN["Multiplayer"] = "多人游戏";
    zhCN["Launch new instance"] = "启动新实例";
    zhCN["Host LAN game"] = "主持局域网游戏";
    zhCN["Join LAN game"] = "加入局域网游戏";

    // View menu
    zhCN["Screen size"] = "屏幕大小";
    zhCN["Screen rotation"] = "屏幕旋转";
    zhCN["Screen gap"] = "屏幕间距";
    zhCN["Screen layout"] = "屏幕布局";
    zhCN["Swap screens"] = "交换屏幕";
    zhCN["Screen sizing"] = "屏幕尺寸模式";
    zhCN["Force integer scaling"] = "强制整数缩放";
    zhCN["Aspect ratio"] = "纵横比";
    zhCN["Open new window"] = "打开新窗口";
    zhCN["Screen filtering"] = "屏幕滤波";
    zhCN["Show OSD"] = "显示 OSD";

    // Screen sizing
    zhCN["Top only"] = "仅上屏";
    zhCN["Bottom only"] = "仅下屏";

    // Screen layout
    zhCN["Natural"] = "自然布局";
    zhCN["Horizontal"] = "水平";
    zhCN["Vertical"] = "垂直";
    zhCN["Hybrid Top"] = "混合上屏";
    zhCN["Hybrid Bottom"] = "混合下屏";
    zhCN["Rotated Left"] = "向左旋转";
    zhCN["Rotated Right"] = "向右旋转";

    // Config menu
    zhCN["Emu settings"] = "模拟器设置";
    zhCN["Preferences..."] = "偏好设置...";
    zhCN["Input and hotkeys"] = "按键和热键";
    zhCN["Video settings"] = "视频设置";
    zhCN["Camera settings"] = "摄像头设置";
    zhCN["Audio settings"] = "音频设置";
    zhCN["Multiplayer settings"] = "多人游戏设置";
    zhCN["Wifi settings"] = "Wifi 设置";
    zhCN["Firmware settings"] = "固件设置";
    zhCN["Interface settings"] = "界面设置";
    zhCN["Path settings"] = "路径设置";
    zhCN["Limit framerate"] = "限制帧率";
    zhCN["Audio sync"] = "音频同步";

    // Help
    zhCN["About..."] = "关于...";

    // Dialog titles
    zhCN["About melonDS"] = "关于 melonDS";
    zhCN["Emu Settings"] = "模拟器设置";
    zhCN["Video Settings"] = "视频设置";
    zhCN["Audio Settings"] = "音频设置";
    zhCN["Camera Settings"] = "摄像头设置";
    zhCN["Firmware Settings"] = "固件设置";
    zhCN["Path Settings"] = "路径设置";
    zhCN["Interface Settings"] = "界面设置";
    zhCN["Input Configuration"] = "按键配置";
    zhCN["Power Management"] = "电源管理";
    zhCN["Date and Time"] = "日期和时间";
    zhCN["Cheat Codes"] = "金手指代码";
    zhCN["ROM Information"] = "ROM 信息";
    zhCN["RAM Search"] = "RAM 搜索";
    zhCN["Title Manager"] = "标题管理器";
    zhCN["Import Cheats"] = "导入金手指";
    zhCN["Save File"] = "保存文件";
    zhCN["Load File"] = "加载文件";

    // Common
    zhCN["All supported files"] = "所有支持的文件";
    zhCN["Confirm"] = "确认";
    zhCN["Cancel"] = "取消";
    zhCN["OK"] = "确定";
    zhCN["Error"] = "错误";
    zhCN["Warning"] = "警告";
    zhCN["Information"] = "提示";
    zhCN["Yes"] = "是";
    zhCN["No"] = "否";
    zhCN["Close"] = "关闭";

    // OSD
    zhCN["Paused"] = "已暂停";
    zhCN["Unpaused"] = "已恢复";
    zhCN["State saved."] = "即时存档已保存。";
    zhCN["State loaded."] = "即时存档已加载。";
    zhCN["Load undone."] = "已撤销加载。";
    zhCN["Cheats enabled."] = "金手指已启用。";
    zhCN["Cheats disabled."] = "金手指已禁用。";
    zhCN["Framerate limited."] = "帧率已限制。";
    zhCN["Framerate unlimited."] = "帧率已取消限制。";
    zhCN["Audio sync enabled."] = "音频同步已启用。";
    zhCN["Audio sync disabled."] = "音频同步已禁用。";
    zhCN["Screen filtering enabled."] = "屏幕滤波已启用。";
    zhCN["Screen filtering disabled."] = "屏幕滤波已禁用。";
    zhCN["OSD enabled."] = "OSD 已启用。";
    zhCN["OSD disabled."] = "OSD 已禁用。";
    zhCN["Cart inserted."] = "卡带已插入。";
    zhCN["Cart ejected."] = "卡带已弹出。";
    zhCN["GBA cart inserted."] = "GBA 卡带已插入。";
    zhCN["GBA cart ejected."] = "GBA 卡带已弹出。";
}

inline QString Tr(const char* text)
{
    if (!isChinese)
        return QString::fromUtf8(text);

    if (zhCN.isEmpty())
        InitTranslations();

    QString key = QString::fromUtf8(text);
    if (zhCN.contains(key))
        return zhCN[key];
    return key;
}

// Also support QString overload
inline QString Tr(const QString& text)
{
    return Tr(text.toUtf8().constData());
}

} // namespace Language

#define LTr(x) Language::Tr(x)

#endif // LANGUAGE_H
