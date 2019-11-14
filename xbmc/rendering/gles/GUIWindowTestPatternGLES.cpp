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
#include "GUIWindowTestPatternGLES.h"
#include "guilib/GUITextureGLES.h"
#include "utils/GLUtils.h"
#include "utils/Geometry.h"
#include "rendering/gl/RenderSystemGLES.h"
#include "utils/Color.h"

CGUIWindowTestPatternGLES::CGUIWindowTestPatternGL(void) : CGUIWindowTestPattern()
{
}

CGUIWindowTestPatternGLES::~CGUIWindowTestPatternGLES(void) = default;

void CGUIWindowTestPatternGLES::BeginRender(UTILS::Color4f bkgcolor)
{
  CRenderSystemGLES *renderSystem = dynamic_cast<CRenderSystemGLES*>(CServiceBroker::GetRenderSystem());
  renderSystem->ClearBuffers(bkgcolor);
}

void CGUIWindowTestPatternGLES::DrawRectangle(CRect &rect, UTILS::Color4f color)
{
  CGUITextureGLES::DrawQuad(rect, color);
}

void CGUIWindowTestPatternGLES::EndRender()
{

}
