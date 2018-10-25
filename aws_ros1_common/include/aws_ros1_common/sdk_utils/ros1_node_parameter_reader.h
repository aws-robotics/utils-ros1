/*
 * Copyright 2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
#pragma once
#include <aws_common/sdk_utils/parameter_reader.h>
#include <ros/ros.h>

namespace Aws {
namespace Client {

/**
 * ROS1-specific parameter reader.
 */
class Ros1NodeParameterReader : public ParameterReaderInterface
{
public:
  AwsError ReadList(const char * name, std::vector<std::string> & out) const override;
  AwsError ReadDouble(const char * name, double & out) const override;
  AwsError ReadInt(const char * name, int & out) const override;
  AwsError ReadBool(const char * name, bool & out) const override;
  AwsError ReadStdString(const char * name, std::string & out) const override;
  AwsError ReadString(const char * name, Aws::String & out) const override;
  AwsError ReadMap(const char * name, std::map<std::string, std::string> & out) const override;
};

}  // namespace Client
}  // namespace Aws
