#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkParametricFunctionSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>


#include <vtkParametricFigure8Klein.h>


#include <array>

int main(int, char* [])
{
  vtkSmartPointer<vtkNamedColors> colors =
    vtkSmartPointer<vtkNamedColors>::New();

  // Set the background color.
  std::array<unsigned char , 4> bkg{{26, 51, 102, 255}};
    colors->SetColor("BkgColor", bkg.data());

  
  vtkSmartPointer<vtkParametricFigure8Klein> parametricObject =
  vtkSmartPointer<vtkParametricFigure8Klein>::New();
  
  vtkSmartPointer<vtkParametricFunctionSource> parametricFunctionSource =
    vtkSmartPointer<vtkParametricFunctionSource>::New();
  parametricFunctionSource->SetParametricFunction(parametricObject);
  parametricFunctionSource->Update();

  // Visualize

  vtkSmartPointer<vtkProperty> backProperty =
    vtkSmartPointer<vtkProperty>::New();
  backProperty->SetColor(colors->GetColor3d("Tomato").GetData());

  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(parametricFunctionSource->GetOutputPort());

  // Create an actor for the contours
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->SetDiffuseColor(
    colors->GetColor3d("Banana").GetData());
  actor->GetProperty()->SetSpecular(.5);
  actor->GetProperty()->SetSpecularPower(20);
  actor->SetBackfaceProperty(backProperty);
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->SetWindowName("Parametric Objects");
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> interactor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(renderWindow);

  renderer->AddActor(actor);
  renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());

  renderWindow->Render();
  interactor->Start();

  return EXIT_SUCCESS;
}
