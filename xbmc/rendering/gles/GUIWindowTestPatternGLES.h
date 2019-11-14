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

class CGUIWindowTestPatternGLES : public CGUIWindowTestPattern
{
public:
  CGUIWindowTestPatternGLES(void);
  ~CGUIWindowTestPatternGLES(void) override;

private:
  void BeginRender(UTILS::Color4f bkgcolor) override;
  void DrawRectangle(CRect &rect, UTILS::Color4f color) override;
  void EndRender() override;
};
