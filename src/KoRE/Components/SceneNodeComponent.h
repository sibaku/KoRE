/*
  Copyright © 2012 The KoRE Project

  This file is part of KoRE.

  KoRE is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KoRE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KoRE.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CORE_INCLUDE_CORE_SCENENODECOMPONENT_H_
#define CORE_INCLUDE_CORE_SCENENODECOMPONENT_H_

#include "KoRE/Common.h"
#include "KoRE/ShaderData.h"

namespace kore {
  enum EComponentType {
    COMPONENT_UNKNOWN     = 0,
    COMPONENT_TRANSFORM   = 1 << 0,
    COMPONENT_MESH        = 1 << 1,
    COMPONENT_CAMERA      = 1 << 2,
    COMPONENT_VALUES      = 1 << 3,
    COMPONENT_LIGHT       = 1 << 4
  };

  class SceneNode;
  typedef std::shared_ptr<SceneNode> SceneNodePtr;
  class Transform;
  typedef std::shared_ptr<Transform> TransformPtr;
  class SceneNodeComponent {
  public:
    explicit SceneNodeComponent(void);
    virtual ~SceneNodeComponent(void);
    /// Checks if this component is of the same type as the other component
    virtual bool isCompatibleWith(const SceneNodeComponent& otherComponent) const = 0;
    virtual void attachTo(SceneNodePtr& node);
    virtual void transformChanged(const TransformPtr& newTransform);
    const EComponentType getType(void) const;
    const ShaderData* getShaderData(const std::string& name) const;

    inline const std::vector<ShaderData>&
      getShaderData() {return _shaderData;}

    uint getID(void) const;

  protected:
    std::string name;
    uint _id;
    SceneNodePtr _sceneNode;
    EComponentType _type;
    std::vector<ShaderData> _shaderData;
  };
  typedef std::shared_ptr<SceneNodeComponent> SceneNodeComponentPtr;
};
#endif  // CORE_INCLUDE_CORE_SCENENODECOMPONENT_H_
