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
  void DrawRectangle(CRect &rect, UTILS::Color4f color) override;
  void EndRender() override;
};
