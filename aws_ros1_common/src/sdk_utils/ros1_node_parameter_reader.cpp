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

#include <aws_ros1_common/sdk_utils/ros1_node_parameter_reader.h>
#include <ros/ros.h>

namespace Aws {
namespace Client {

template <class T>
static AwsError ReadParam(const char * name, T & out)
{
  std::string key;
  if (ros::param::search(name, key) && ros::param::get(key, out)) {
    return AWS_ERR_OK;
  }
  return AWS_ERR_NOT_FOUND;
}

AwsError Ros1NodeParameterReader::ReadList(const char * name, std::vector<std::string> & out) const
{
  return ReadParam(name, out);
}

AwsError Ros1NodeParameterReader::ReadDouble(const char * name, double & out) const
{
  return ReadParam(name, out);
}

AwsError Ros1NodeParameterReader::ReadInt(const char * name, int & out) const
{
  return ReadParam(name, out);
}

AwsError Ros1NodeParameterReader::ReadBool(const char * name, bool & out) const
{
  return ReadParam(name, out);
}

AwsError Ros1NodeParameterReader::ReadStdString(const char * name, std::string & out) const
{
  return ReadParam(name, out);
}

AwsError Ros1NodeParameterReader::ReadString(const char * name, Aws::String & out) const
{
  std::string value;
  AwsError result = ReadStdString(name, value);
  if (result == AWS_ERR_OK) {
    out = Aws::String(value.c_str());
  }
  return result;
}

AwsError Ros1NodeParameterReader::ReadMap(const char * name,
                                          std::map<std::string, std::string> & out) const
{
  return ReadParam(name, out);
}

}  // namespace Client
}  // namespace Aws
