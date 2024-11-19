#!/bin/bash

llvm-profdata-18 merge default.profraw -o coverage.profdata
rm -r coverage_html_report
mkdir coverage_html_report
llvm-cov-18 show test_stack -instr-profile=coverage.profdata -show-line-counts-or-regions -format="html" -output-dir=./coverage_html_report -ignore-filename-regex='test/.*'