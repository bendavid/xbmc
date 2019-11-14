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

void CGUIWindowTestPatternDX::BeginRender(UTILS::Color4f bkgcolor)
{
  ComPtr<ID3D11DeviceContext> pContext = DX::DeviceResources::Get()->GetD3DContext();
  ID3D11RenderTargetView* renderTarget;

  XMFLOAT4 float4;
  float4.x = bkgcolor.r();
  float4.y = bkgcolor.g();
  float4.z = bkgcolor.b();
  float4.w = bkgcolor.a();
  
  pContext->OMGetRenderTargets(1, &renderTarget, NULL);
  pContext->ClearRenderTargetView(renderTarget, float4);
  renderTarget->Release();
}

void CGUIWindowTestPatternDX::EndRender()
{
  DX::Windowing()->GetGUIShader()->RestoreBuffers();
}

void CGUIWindowTestPatternDX::DrawRectangle(CRect &rect, UTILS::Color4f color)
{
  XMFLOAT4 float4;
  float4.x = color.r();
  float4.y = color.g();
  float4.z = color.b();
  float4.w = color.a();
  
  float x = rect.x1;
  float y = rect.y1;
  float x2 = rect.x2;
  float y2 = rect.y2;

  Vertex vert[] =
  {
    { XMFLOAT3( x, y, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
    { XMFLOAT3(x2, y, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
    { XMFLOAT3(x2, y2, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
    { XMFLOAT3(x2, y2, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
    { XMFLOAT3(x, y2, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
    { XMFLOAT3( x, y, 0.5f), float4, XMFLOAT2(0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
  };

  UpdateVertexBuffer(vert, ARRAYSIZE(vert));

  ComPtr<ID3D11DeviceContext> pContext = DX::DeviceResources::Get()->GetD3DContext();
  CGUIShaderDX* pGUIShader = DX::Windowing()->GetGUIShader();

  pGUIShader->Begin(SHADER_METHOD_RENDER_DEFAULT);
  unsigned stride = sizeof(Vertex), offset = 0;
  pContext->IASetVertexBuffers(0, 1, m_vb.GetAddressOf(), &stride, &offset);
  pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
  pGUIShader->Draw(ARRAYSIZE(vert), 0);
}

void CGUIWindowTestPatternDX::UpdateVertexBuffer(Vertex *vertices, unsigned count)
{
  unsigned width = sizeof(Vertex) * count;

  if (!m_vb || width > m_bufferWidth) // create new
  {
    CD3D11_BUFFER_DESC desc(width, D3D11_BIND_VERTEX_BUFFER, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE);
    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices;
    initData.SysMemPitch = width;

    ComPtr<ID3D11Device1> pDevice = DX::DeviceResources::Get()->GetD3DDevice();
    if (SUCCEEDED(pDevice->CreateBuffer(&desc, &initData, m_vb.ReleaseAndGetAddressOf())))
    {
      m_bufferWidth = width;
    }
    return;
  }
  else // update
  {
    ComPtr<ID3D11DeviceContext> pContext = DX::DeviceResources::Get()->GetD3DContext();
    D3D11_MAPPED_SUBRESOURCE res;
    if (SUCCEEDED(pContext->Map(m_vb.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &res)))
    {
      memcpy(res.pData, vertices, sizeof(Vertex) * count);
      pContext->Unmap(m_vb.Get(), 0);
    }
  }
}
