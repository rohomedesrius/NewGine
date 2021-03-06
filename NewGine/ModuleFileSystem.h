

#ifndef __MODULEFILESYSTEM_H__
#define __MODULEFILESYSTEM_H__

#include "Module.h"
#include "Assimp\include\cfileio.h"


struct SDL_RWops;
int close_sdl_rwops(SDL_RWops *rw);

class ModuleFileSystem : public Module
{
public:

	ModuleFileSystem(Application* app, bool start_enabled = true);
	~ModuleFileSystem();

	bool Init();
	bool CleanUp();

	bool AddPath(const char *path_or_zip, const char *mount_point = NULL);
	//bool RemoveAllSearchPaths();
	//bool RemovePath(const char *path_or_zip);
	uint Load(const char* file, char **buffer) const;
	SDL_RWops *Load(const char* file) const;
	uint Save(const char *file, const char *buffer, uint size) const;

	const char *GetSaveDirectory() const;
	bool IsDirectory(const char *file) const;
	bool Exists(const char *file) const;

	aiFileIO * ModuleFileSystem::GetAssimpIO();

private:

	aiFileIO* AssimpIO = nullptr;

private:

	void ModuleFileSystem::CreateAssimpIO();

};


#endif //!__MODULEFILESYSTEM_H__