/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *      Test patterns designed by Ofer LaOr - hometheater.co.il
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "settings/windows/GUIWindowTestPattern.h"

class CGUIWindowTestPatternGL : public CGUIWindowTestPattern
{
public:
  CGUIWindowTestPatternGL(void);
  ~CGUIWindowTestPatternGL(void) override;

private:
  void BeginRender(float bkgcolour[4]) override;
  void DrawRectangle(float x1, float y1, float x2, float y2, float colour[4]) override;
  void EndRender() override;
};

