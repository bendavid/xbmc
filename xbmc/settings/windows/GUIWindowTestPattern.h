/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "guilib/GUIWindow.h"
#include <atomic>

#define TEST_PATTERNS_COUNT 5
#define TEST_PATTERNS_BOUNCE_SQUARE_SIZE 100
#define TEST_PATTERNS_BLINK_CYCLE 100

// struct TPGParams {
//   float r;
//   float g;
//   float b;
//   float bkg_r;
//   float bkg_g;
//   float bkg_b;
//   float x;
//   float y;
//   float w;
//   float h;
// }

class CGUIWindowTestPattern : public CGUIWindow
{
public:
  CGUIWindowTestPattern(void);
  ~CGUIWindowTestPattern(void) override;
  void Render() override;
  void Process(unsigned int currentTime, CDirtyRegionList &dirtyregions) override;

protected:
  virtual void BeginRender(float bkgcolour[4]) = 0;
  virtual void DrawRectangle(float x1, float y1, float x2, float y2, float colour[4]) = 0;
  virtual void EndRender() = 0;

//   std::atomic<TPGParams> m_tpgParams;
};


