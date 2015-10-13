/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerInteractiveTubesToTreeLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerInteractiveTubesToTreeLogic_h
#define __vtkSlicerInteractiveTubesToTreeLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"
class vtkSlicerCLIModuleLogic;
class vtkSlicerSpatialObjectsLogic;
class vtkMRMLVolumeNode;

// MRML includes

// STD includes
#include <cstdlib>

// MRML includes
#include "vtkMRMLSpatialObjectsNode.h"

#include "vtkSlicerInteractiveTubesToTreeModuleLogicExport.h"


/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_INTERACTIVETUBESTOTREE_MODULE_LOGIC_EXPORT vtkSlicerInteractiveTubesToTreeLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerInteractiveTubesToTreeLogic *New();
  vtkTypeMacro(vtkSlicerInteractiveTubesToTreeLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  void SetConversionLogic(vtkSlicerCLIModuleLogic* logic);
  vtkSlicerCLIModuleLogic* GetConversionLogic();
  void SetSpatialObjectsLogic(vtkSlicerSpatialObjectsLogic* logic);
  vtkSlicerSpatialObjectsLogic* GetSpatialObjectsLogic();

  bool Apply(vtkMRMLSpatialObjectsNode* spatialNode, vtkMRMLSpatialObjectsNode* volumeNode, double maxTubeDistanceToRadiusRatio,
    double maxContinuityAngleError, bool removeOrphanTubes, std::string rootTubeIdList);
  std::string ConstructTemporaryFileName(const std::string& name);
  std::string SaveSpatialObjectNode(vtkMRMLSpatialObjectsNode *spatialObjectsNode);
  std::string GetOutputFileName();
  void SetOutputFileName(std::string name);

protected:
  vtkSlicerInteractiveTubesToTreeLogic();
  virtual ~vtkSlicerInteractiveTubesToTreeLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);

private:

  vtkSlicerInteractiveTubesToTreeLogic(const vtkSlicerInteractiveTubesToTreeLogic&); // Not implemented
  void operator=(const vtkSlicerInteractiveTubesToTreeLogic&); // Not implemented
  class vtkInternal;
  vtkInternal* Internal;
  std::string OutputFileName;
};

#endif
