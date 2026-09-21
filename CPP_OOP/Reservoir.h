#pragma once

enum class ReservoirType
{
	Ocean, Sea, Lake
};

class Reservoir
{
	ReservoirType type;

public:
	Reservoir(ReservoirType t) : type{ t } {}
	ReservoirType getType() const { return type; }
	void setType(ReservoirType t) { type = t; }
};