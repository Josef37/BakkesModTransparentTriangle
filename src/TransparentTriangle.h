#pragma once

#include <memory>

class ImageWrapper;
class CanvasWrapper;
class Vector2F;

class TransparentTriangle
{
public:
	// Expects an image a of right-triangle with its right angle in the bottom-left corner.
	TransparentTriangle(std::shared_ptr<ImageWrapper> triangleImage);

	// Renders a triangle respecting transparency.
	// The points can be in any order.
	void Render(CanvasWrapper canvas, Vector2F p1, Vector2F p2, Vector2F p3);

	// Rendering examples. Feel free to delete them.
	void Test(CanvasWrapper canvas);
	void TestTouching(CanvasWrapper canvas);

private:
	std::shared_ptr<ImageWrapper> triangleImage;

	// Points are expected to be ordered counter-clockwise with `c` opposite to the hypotenuse.
	// To avoid clipping at the canvas edge, the triangle has to be fully inside the canvas before rotation.
	void RenderRightTriangle(CanvasWrapper canvas, Vector2F a, Vector2F b, Vector2F c);
};
