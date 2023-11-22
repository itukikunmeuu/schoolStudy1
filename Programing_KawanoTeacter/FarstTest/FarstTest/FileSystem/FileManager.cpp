#include "FileManager.h"
#include <DxLib.h>
#include "ImageFile.h"
#include <cassert>

std::shared_ptr<File> FileManager::LoadGraphic(const std::wstring& path)
{
    // もし、ロード済みのファイルがあったらそのファイルを返す
    if (m_fileTable.find(path) != m_fileTable.end())
    {
        auto file = m_fileTable.at(path);
        std::shared_ptr<ImageFile> imgFiile = 
            std::dynamic_pointer_cast<ImageFile>(file);
        assert(imgFiile != nullptr);
        ++file->m_count;
        return std::make_shared<ImageFile>(m_fileTable.at(path));
    }
    int handle = LoadGraph(path.c_str());
    std::shared_ptr < File>ret = std::make_shared<ImageFile>(*this);
    ret->m_handle = handle;
    ret->m_path = path;
    ret->m_count = 1;
    return ret;
}

void FileManager::Delete(const std::wstring& path)
{
    /*if (m_fileTable.find(path) != m_fileTable.end())
    {
        return;
    }
    auto file = m_fileTable.at(path);
    if (file)
    file->Delete();*/
}
