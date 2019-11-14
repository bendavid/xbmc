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
#include "guilib/GUIShaderDX.h"
#include "utils/Geometry.h"
#include "utils/Color.h"

#include <wrl/client.h>

class CGUIWindowTestPatternDX : public CGUIWindowTestPattern
{
public:
  CGUIWindowTestPatternDX(void);
  virtual ~CGUIWindowTestPatternDX(void);

protected:
  void DrawRectangle(CRect &rect, UTILS::Color4f color) override;
  void EndRender() override;
};

