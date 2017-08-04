#pragma once
class CObj;
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute(CObj& actor)PURE;
};

