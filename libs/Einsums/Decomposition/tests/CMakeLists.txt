#----------------------------------------------------------------------------------------------
# Copyright (c) The Einsums Developers. All rights reserved.
# Licensed under the MIT License. See LICENSE.txt in the project root for license information.
#----------------------------------------------------------------------------------------------

include(Einsums_Message)

if(EINSUMS_WITH_TESTS)
  if(EINSUMS_WITH_TESTS_UNIT)
    einsums_add_pseudo_target(Tests.Unit.Modules.Decomposition)
    einsums_add_pseudo_dependencies(Tests.Unit.Modules Tests.Unit.Modules.Decomposition)
    add_subdirectory(unit)
  endif()

  if(EINSUMS_WITH_TESTS_REGRESSIONS)
    einsums_add_pseudo_target(Tests.Regressions.Modules.Decomposition)
    einsums_add_pseudo_dependencies(
      Tests.Regressions.Modules Tests.Regressions.Modules.Decomposition
    )
    add_subdirectory(regressions)
  endif()

  if(EINSUMS_WITH_TESTS_BENCHMARKS)
    einsums_add_pseudo_target(Tests.Performance.Modules.Decomposition)
    einsums_add_pseudo_dependencies(
      Tests.Performance.Modules Tests.Performance.Modules.Decomposition
    )
    add_subdirectory(performance)
  endif()

  if(EINSUMS_WITH_TESTS_HEADERS)
    einsums_add_header_tests(
      Modules.Decomposition
      HEADERS ${DecompositionHeaders}
      HEADER_ROOT ${PROJECT_SOURCE_DIR}/include
      DEPENDENCIES einsums_Decomposition
    )
  endif()
endif()
