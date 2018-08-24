#include "System/Window.hpp"

#include "Rendering/Mesh.hpp"
#include "Rendering/Shader.hpp"

int main()
{
	Atena::Window window(800, 600);

	std::vector<Atena::Vertex> vertices =
	{
		Atena::Vertex({0.0f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}),
		Atena::Vertex({0.5, -0.5, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}),
		Atena::Vertex({-0.5, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f})
	};

	Atena::Mesh mesh(vertices, window.getContext());
	Atena::Shader shader("shader.shader", window.getContext());
	shader.bind();

	while (!window.isClosed())
	{
		if (window.pollEvents())
		{

		}
		else
		{
			window.getContext()->clear();

			mesh.draw();

			window.getContext()->present();
		}
	}

	return 0;
}