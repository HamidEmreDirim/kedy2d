#pragma once

#include <map>
#include <string>
#include "GameMap.h"
#include "TileLayer.h"
#include "tinyxml.h"

class MapParser
{
public:
	bool Load();
	void Clean();

	inline GameMap* GetMaps();

	inline static MapParser* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser(); }

private:
	bool Parse(std::string id, std::string source);
	Tileset ParseTileset(TiXmlElement* xmkTileset);
	TileLayer* ParseTileLayer(TiXmlElement* xmlLayer);

private:
	MapParser(){}
	static MapParser* s_Instance;
	std::map<std::string, GameMap*> m_MapDict;

};

