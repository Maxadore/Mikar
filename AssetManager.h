#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

class AssetManager
{
public:

	// Constructor & Destructor 
	AssetManager() { }
	~AssetManager() { }

	// Functions
	void LoadTexture(string name, string fileName);		
	void LoadFont(string name, string fileName);		

	// Getters
	Texture& GetTexture(string name);
	Font& GetFont(string name);

private:
	map<string, Texture> m_textures;
	map<string, Font> m_fonts;
};

#endif // ASSETMANAGER_H

