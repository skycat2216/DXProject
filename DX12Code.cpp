//Special Thanks To GamebabyRockSum_QQ

#include<sdkddkver.h>

#define WIN32_LEAN_AND_MEAN //Exclude the rarely use data from windows.h

#include<windows.h>
#include<tchar.h>
#include<wrl.h> //WTL Support
using namespace Microsoft;
using namespace Microsoft::WRL;

#include<dxgi1_6.h>
#include<DirectXMath.h>
using namespace DirectX; //D3D12

#include<d3d12.h>
#include<d3d12shader.h>
#include<d3dcompiler.h>
#include"DirectX-Headers/include/directx/d3dx12.h"

#include<strsafe.h>

#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"d3dcompiler.lib")

#if defined(_DEBUG)
#include<dxgidebug.h>
#endif

#define GRS_WND_CLASS_NAME _T("Game Window Class")
#define GRS_WND_TITLE _T("DirectX12 TRigger Sample")

#define GRS_EXPECTION_THROW(hr){HRESULT _hr = (hr); if (FAILED(hr)){ throw CGRSCOMExpection(_hr); }}

class  CGRSCOMExpection
{
public:
    CGRSCOMExpection(HRESULT hr) : m_hrError(hr)
    {

    }
    HRESULT Error() const
    {
        return m_hrError;
    }

private:
    const HRESULT m_hrError;

};



struct GRS_VERTEX
{
    XMFLOAT3 position;
    XMFLOAT4 color;
};

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);





int APIENTRY _tWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPWSTR lpCmdline, int CmdShow)
{
    const UINT FrameBackBufCount = 3u;

    int																					wndWidth = 1024;
    int																					wndHeight = 768;
    UINT																				FrameIndex = 0;
    UINT																				Frame = 0;

    UINT																				DXGIFactoryFlags = 0U;
    UINT																				RVTDescriptorSize = 0U;

    HWND																			hwnd = nullptr;
    MSG																				msg = {};
    TCHAR																			pszAppPath[MAX_PATH] = { };

    float AspectRatio = 3.0f;

    D3D12_VERTEX_BUFFER_VIEW StVretexBufferView = {};

    UINT64 SixFourFenceValue = 0ui64;
    HANDLE FenceEvent = nullptr;

    CD3DX12_VIEWPORT ViewPort(0.0f, 0.0f, static_cast<float>(wndWidth), static_cast<float>(wndHeight));
    CD3DX12_RECT ScissorRect(0, 0, static_cast<LONG>(wndWidth), static_cast<LONG>(wndHeight));

    ComPtr<IDXGIFactory5>									comDXGIFactory5;
    ComPtr<IDXGIAdapter>										comAdapter;
    ComPtr<ID3D12Device4>									comD3DDevice;
    ComPtr<ID3D12CommandQueue>				comD3D12CommandQuene;
    ComPtr<IDXGISwapChain1>							    comSwapChain1;
    ComPtr<IDXGISwapChain3>							    comSwapChain3;
    ComPtr<ID3D12DescriptorHeap>					comRTVHeap;
    ComPtr<ID3D12Resource>							    comRenderTarget[FrameBackBufCount];
    ComPtr<ID3D12CommandAllocator>			comCommandAllocator;
    ComPtr<ID3D12RootSignature>						comRootSingnature;
    ComPtr<ID3D12PipelineState>						comPipelineState;
    ComPtr<ID3D12GraphicsCommandList>	comCommandList;
    ComPtr<ID3D12Resource>								comVretexBuffer;
    ComPtr<ID3D12Fence>										comFence;




    try
    {
        if (0 == ::GetModuleFileName(nullptr, pszAppPath, MAX_PATH))
        {
            GRS_EXPECTION_THROW(HRESULT_FROM_WIN32(GetLastError()));
        }
      
        WCHAR* lastSlash = _tcsrchr(pszAppPath, _T('\\'));

    }
    catch (CGRSCOMExpection& e)
    {
        e;
    }
    return 0;
}


