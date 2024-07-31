/*
*	BSD 3-Clause License

	Copyright (c) 2024, Alex

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	   list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	   contributors may be used to endorse or promote products derived from
	   this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define DGE_PHYSICS
#include "defGeometry2D.hpp"

#define DGE_IGNORE_VEC2D
#define DGE_APPLICATION
#include "defGameEngine.hpp"

class Engine3D : public def::GameEngine
{
public:
	Engine3D()
	{
		SetTitle("Math library");
	}

	def::line<float> l1;
	def::line<float> l2;

protected:
	bool OnUserCreate() override
	{
		l1.pos[0] = { 128, 210 };
		l2.pos[1] = { 240, 200 };

		return true;
	}

	bool OnUserUpdate(float dt) override
	{
		l1.pos[1] = GetMouse();

		/*for (int i = 0; i < 4; i++)
		{
			def::line<float> l = r.side(i);

			DrawLine(l.pos[0], l.pos[1], def::YELLOW);
		}*/

		Clear(def::BLACK);

		auto res = intersects(l1, l2);
		
		/*if (res)
		{
			DrawString(0, 0, "It does!");
		}*/

		DrawLine(l1.pos[0], l1.pos[1]);
		DrawLine(l2.pos[0], l2.pos[1]);

		if (res.size() > 0)
		{
			for (const auto& p : res)
				FillCircle(p, 3, def::RED);
		}

		return true;
	}
};

int main()
{
	Engine3D demo;

	demo.Construct(256, 240, 4, 4);
	demo.Run();

	return 0;
}
