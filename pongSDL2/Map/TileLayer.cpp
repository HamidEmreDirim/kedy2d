#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets) {
	m_TileSize = tileSize;
	m_RowCount = rowcount;
	m_ColCount = colcount;
	m_Tilemap = tilemap;
	m_Tilesets = tilesets;



}
