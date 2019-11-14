/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *      Test patterns designed by Ofer LaOr - hometheater.co.il
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "system_gl.h"
#include "GUIWindowTestPatternGL.h"
#include "guilib/GUITextureGL.h"
#include "utils/GLUtils.h"
#include "utils/Geometry.h"
#include "rendering/gl/RenderSystemGL.h"
#include "utils/Color.h"

CGUIWindowTestPatternGL::CGUIWindowTestPatternGL(void) : CGUIWindowTestPattern()
{
}

CGUIWindowTestPatternGL::~CGUIWindowTestPatternGL(void) = default;

void CGUIWindowTestPatternGL::BeginRender(UTILS::Color4f bkgcolor)
{
  CRenderSystemGL *renderSystem = dynamic_cast<CRenderSystemGL*>(CServiceBroker::GetRenderSystem());
  renderSystem->ClearBuffers(bkgcolor);
}

void CGUIWindowTestPatternGL::DrawRectangle(CRect &rect, UTILS::Color4f color)
{
  CGUITextureGL::DrawQuad(rect, color);
}

void CGUIWindowTestPatternGL::EndRender()
{

}
