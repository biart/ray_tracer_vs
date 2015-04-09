#pragma once

#include "glm/glm.hpp"
#include "Types.h"
#include "Scene.h"

#include "string"

class Renderer
{
public:
    Camera camera; // Camera
    Scene* scene; // Scene

    // Render image
    virtual void Render(glm::uvec2 resolution) = 0;

    virtual ~Renderer() {};
};

class RayTracer : public Renderer
{
public:
	// Make ray that corresponds specified pixel position on the image
	// Depends on the camera
    Ray MakeRay(glm::uvec2 pixelPos);

	// Trace the specified ray
	// Returns pixel color
    glm::dvec3 TraceRay(Ray ray, int step);

	// Render image
    void Render(glm::uvec2 resolution);

	// Save rendered image to specified file
    void SaveImageToFile(std::string fileName);

	glm::uvec2 resolution;  // Image resolution
	std::vector<glm::dvec3> pixels;  // Pixel array

    int maxRenderStep = 10;  // Maximal tracing deepness
    glm::dvec3 backgroundColor; // Default color (is set when no intersections were found)
};