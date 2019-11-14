/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *      Test patterns designed by Ofer LaOr - hometheater.co.il
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "GUIWindowTestPatternDX.h"
#include "rendering/dx/DeviceResources.h"
#include "rendering/dx/RenderContext.h"
#include "guilib/GUITextureDX.h"
#ifndef _d3d9TYPES_H_
#include "DirectXPackedVector.h"
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;

DWORD D3DCOLOR_COLORVALUE(float r, float g, float b, float a)
{
  XMCOLOR xColor;
  XMVECTOR xVector = XMVectorSet(r, g, b, a);
  XMStoreColor(&xColor, xVector);
  DWORD color = xColor;
  return color;
}
#endif

CGUIWindowTestPatternDX::CGUIWindowTestPatternDX(void) : CGUIWindowTestPattern()
{
  m_vb = nullptr;
  m_bufferWidth = 0;
}

CGUIWindowTestPatternDX::~CGUIWindowTestPatternDX(void)
{
  m_vb = nullptr;
  m_bufferWidth = 0;
}

void CGUIWindowTestPatternDX::EndRender()
{
  DX::Windowing()->GetGUIShader()->RestoreBuffers();
}

void CGUIWindowTestPatternDX::DrawRectangle(CRect &rect, UTILS::Color4f color)
{
  GUITextureDX::DrawQuad(rect, color);
}
