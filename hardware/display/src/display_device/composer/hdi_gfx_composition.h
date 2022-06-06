/*
 * Copyright© 2021–2022 Beijing OSWare Technology Co., Ltd
 * This file contains confidential and proprietary information of
 * OSWare Technology Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HDI_GFX_COMPOSITION_H
#define HDI_GFX_COMPOSITION_H
#include "display_gfx.h"
#include "hdi_composer.h"
namespace OHOS {
namespace HDI {
namespace DISPLAY {
class HdiGfxComposition : public HdiComposition {
public:
    int32_t Init(void) override;
    int32_t SetLayers(std::vector<HdiLayer *> &layers, HdiLayer &clientLayer) override;
    int32_t Apply(bool modeSet) override;
    ~HdiGfxComposition() override
    {
        (void)GfxModuleDeinit();
    }

private:
    bool CanHandle(HdiLayer &hdiLayer);
    void InitGfxSurface(ISurface &surface, HdiLayerBuffer &buffer);
    int32_t BlitLayer(HdiLayer &src, HdiLayer &dst);
    int32_t ClearRect(HdiLayer &src, HdiLayer &dst);
    int32_t GfxModuleInit(void);
    int32_t GfxModuleDeinit(void);
    void *mGfxModule = nullptr;
    GfxFuncs *mGfxFuncs = nullptr;
    HdiLayer *mClientLayer;
    static constexpr const char* LIB_HDI_GFX_NAME = "libdisplay_gfx.z.so";
    static constexpr const char* LIB_GFX_FUNC_INIT = "GfxInitialize";
    static constexpr const char* LIB_GFX_FUNC_DEINIT = "GfxUninitialize";
    bool valid_ = false;
};
} // namespace OHOS
} // namespace HDI
} // namespace DISPLAY

#endif // HDI_GFX_COMPOSITION_H