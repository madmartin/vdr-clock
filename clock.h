/*
 * clock.h: A plugin for the Video Disk Recorder
 *
 * Clock Plugin for VDR. See http://vdr.aistleitner.info for download.
 * Copyright (C) 2007  Mario Aistleitner <vdr@aistleitner.info>
 *           (C) 2019  Martin Dummer <martin.dummer@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef VDR_CLOCK_H
#define VDR_CLOCK_H

#include "enhancedbitmap.h"

class cOSDClock : public cOsdObject, public cThread {
private:
  cOsd *osd;
  eKeys LastKey;
  bool shutdown;
  tColor ColorH, ColorM, ColorS, ColorForeGround, ColorBackGround;
  int r;
  void DrawArrow(double width, double len, tColor col, double ang,
                 cEnhancedBitmap &img);
  void DrawScale(int r, tColor col, cEnhancedBitmap &Analog);
  void DrawModernSec(int r, int sec, tColor col, cEnhancedBitmap &Analog);
  void DrawPoint(double x, double y, int r, tColor col,
                 cEnhancedBitmap &Analog);
  tColor getColor(int color);
  static cBitmap bmClock;
  static cBitmap bmTux;
  static cBitmap bmTuxpart;

protected:
  virtual void Action(void);

public:
  cOSDClock(void);
  virtual ~cOSDClock(void);
  void Show(void);
  eOSState ProcessKey(eKeys Key);
};

class cPluginClock : public cPlugin {
private:
  // Add any member variables or functions you may need here.
public:
  static bool VDR_readyafterStartup;
  static bool ClockIsVisible;
  cPluginClock(void);
  virtual ~cPluginClock();
  virtual const char *Version(void);
  virtual const char *Description(void);
  virtual const char *CommandLineHelp(void);
  virtual bool ProcessArgs(int argc, char *argv[]);
  virtual bool Initialize(void);
  virtual bool Start(void);
  virtual void Housekeeping(void);
  virtual const char *MainMenuEntry(void);
  virtual cOsdObject *MainMenuAction(void);
  virtual cMenuSetupPage *SetupMenu(void);
  virtual bool SetupParse(const char *Name, const char *Value);
};

#endif
