# BakkesModTransparentTriangle

A utility for [BakkesMod](https://bakkesplugins.com/) that allows transparency for triangles.

## Usage Example

```cpp
void YourPlugin::onLoad()
{
    // Make sure to distribute the triangle template image with your plugin!
    triangleImage = std::make_shared<ImageWrapper>(gameWrapper->GetDataFolder() / "your-plugin" / "triangle.png", true, false);
    transparentTriangle = std::make_shared<TransparentTriangle>(triangleImage);

    gameWrapper->RegisterDrawable([this](CanvasWrapper canvas)
        {
            // Render a lonely triangle...
            canvas.SetColor({ 0, 255, 0, 127 });
            Vector2F p1 = { 700, 700 };
            Vector2F p2 = { 300, 600 };
            Vector2F p3 = { 200, 500 };
            transparentTriangle->Render(canvas, p1, p2, p3);

            // More rendering examples. Feel free to delete them.
            //transparentTriangle->Test(canvas);
            //transparentTriangle->TestTouching(canvas);
        }
    );
}
```
