// Aseprite
// Copyright (C) 2017  David Capello
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_UI_SKIN_FONT_DATA_H_INCLUDED
#define APP_UI_SKIN_FONT_DATA_H_INCLUDED
#pragma once

#include "base/disable_copying.h"
#include "she/font.h"

#include <map>

namespace app {
namespace skin {

  class FontData {
  public:
    FontData(she::FontType type);
    ~FontData();

    void setFilename(const std::string& filename) { m_filename = filename; }
    void setAntialias(bool antialias) { m_antialias = antialias; }
    void setFallback(FontData* fallback, int fallbackSize) {
      m_fallback = fallback;
      m_fallbackSize = fallbackSize;
    }

    she::Font* getFont(int size);

  private:
    she::FontType m_type;
    std::string m_filename;
    bool m_antialias;
    std::map<int, she::Font*> m_fonts; // key=font size, value=real font
    FontData* m_fallback;
    int m_fallbackSize;

    DISABLE_COPYING(FontData);
  };

} // namespace skin
} // namespace app

#endif
