//
// Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <boost/test/unit_test.hpp>

#include <envire_core/plugin/ClassLoader.hpp>
#include <envire_core/items/Item.hpp>
#include <octomap/AbstractOcTree.h>

BOOST_AUTO_TEST_CASE(abstract_octree_plugin_test)
{
    BOOST_CHECK(envire::core::ClassLoader::getInstance()->hasEnvireItem("envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>"));
    envire::core::ItemBase::Ptr base_plugin;
    BOOST_CHECK(envire::core::ClassLoader::getInstance()->createEnvireItem("envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>", base_plugin));
    envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>::Ptr map_plugin = boost::dynamic_pointer_cast< envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>> >(base_plugin);
    BOOST_CHECK(map_plugin != NULL);
    std::string class_name;
    BOOST_CHECK(map_plugin->getClassName(class_name));
    BOOST_CHECK(class_name == "envire::core::Item<boost::shared_ptr<octomap::AbstractOcTree>>");
}