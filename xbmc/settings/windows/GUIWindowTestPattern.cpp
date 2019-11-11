/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "GUIWindowTestPattern.h"
#include "ServiceBroker.h"
#include "input/Key.h"
#include "guilib/GUIMessage.h"
#include "guilib/WindowIDs.h"
#include "windowing/WinSystem.h"
#include "utils/Variant.h"
#include <iostream>


CGUIWindowTestPattern::CGUIWindowTestPattern(void)
    : CGUIWindow(WINDOW_TEST_PATTERN, "")
{

  std::map<std::string, CVariant> tpgParams;
  tpgParams["r"] = 0.;
  tpgParams["g"] = 0.;
  tpgParams["b"] = 0.;
  tpgParams["bkg_r"] = 0.2;
  tpgParams["bkg_g"] = 0.2;
  tpgParams["bkg_b"] = 0.2;
  tpgParams["x"] = 0.5*(1.-sqrt(0.1));
  tpgParams["y"] = 0.5*(1.-sqrt(0.1));
  tpgParams["w"] = sqrt(0.1);
  tpgParams["h"] = sqrt(0.1);
  
  SetProperty("tpgParams",tpgParams);
}

CGUIWindowTestPattern::~CGUIWindowTestPattern(void) = default;

void CGUIWindowTestPattern::Process(unsigned int currentTime, CDirtyRegionList &dirtyregions)
{
  //*TODO* Update only on demand
  MarkDirtyRegion();
  CGUIWindow::Process(currentTime, dirtyregions);
  m_renderRegion.SetRect(0, 0, (float)CServiceBroker::GetWinSystem()->GetGfxContext().GetWidth(), (float)CServiceBroker::GetWinSystem()->GetGfxContext().GetHeight());

}

void CGUIWindowTestPattern::Render()
{
  const CVariant& tpgParams = GetProperty("tpgParams");

  float bkgcolour[4] = {tpgParams["bkg_r"].asFloat(), tpgParams["bkg_g"].asFloat(), tpgParams["bkg_b"].asFloat(), 1.};
  float colour[4]  = {tpgParams["r"].asFloat(), tpgParams["g"].asFloat(), tpgParams["b"].asFloat(), 1.};
  float x1 = 2.*tpgParams["x"].asFloat() - 1.;
  float y1 = 2.*tpgParams["y"].asFloat() - 1.;
  float w = 2.*tpgParams["w"].asFloat();
  float h = 2.*tpgParams["h"].asFloat();
  float x2 = x1 + w;
  float y2 = y1 + h;

  BeginRender(bkgcolour);
  DrawRectangle(x1, y1, x2, y2, colour);
  EndRender();

  CGUIWindow::Render();
}

