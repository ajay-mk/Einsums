#----------------------------------------------------------------------------------------------
# Copyright (c) The Einsums Developers. All rights reserved.
# Licensed under the MIT License. See LICENSE.txt in the project root for license information.
#----------------------------------------------------------------------------------------------

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(GraphHeaders)

set(GraphSources)

include(Einsums_AddModule)
einsums_add_module(
  EinsumsExperimental Graph
  SOURCES ${GraphSources}
  HEADERS ${GraphHeaders}
  DEPENDENCIES Einsums
  MODULE_DEPENDENCIES
  CMAKE_SUBDIRS examples tests
  BASE_LIBNAME EinsumsExperimental
)
