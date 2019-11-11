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

#include <wrl/client.h>

class CGUIWindowTestPatternDX : public CGUIWindowTestPattern
{
public:
  CGUIWindowTestPatternDX(void);
  virtual ~CGUIWindowTestPatternDX(void);

protected:
  void BeginRender(float bkgcolour[4]) override;
  void DrawRectangle(float x, float y, float x2, float y2, float colour[4]) override;
  void EndRender() override;

private:
  void UpdateVertexBuffer(Vertex *vertices, unsigned count);

  unsigned m_bufferWidth;
  Microsoft::WRL::ComPtr<ID3D11Buffer> m_vb;
};

