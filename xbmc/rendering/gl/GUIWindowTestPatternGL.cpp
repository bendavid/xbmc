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
#include "utils/Variant.h"

CGUIWindowTestPatternGL::CGUIWindowTestPatternGL(void) : CGUIWindowTestPattern()
{
}

CGUIWindowTestPatternGL::~CGUIWindowTestPatternGL(void) = default;

void CGUIWindowTestPatternGL::BeginRender(float bkgcolour[4])
{
  glClearColor(bkgcolour[0], bkgcolour[1], bkgcolour[2], bkgcolour[3]);
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CGUIWindowTestPatternGL::DrawRectangle(float x1, float y1, float x2, float y2, float colour[4])
{
  glColor4f(colour[0], colour[1], colour[2], colour[3]);
  glRectf(x1,y1,x2,y2);
}

void CGUIWindowTestPatternGL::EndRender()
{

}
