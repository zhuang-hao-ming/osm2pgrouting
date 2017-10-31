/*PGR-GNU*****************************************************************

 Copyright (c) 2017 pgRouting developers
 Mail: project@pgrouting.org

 ------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
********************************************************************PGR-GNU*/

#include <string>
#include <vector>


/**
*  ["a","b","c"] => " a,b,c "
*/
std::string 
comma_separated(const std::vector<std::string> &columns) {
    std::string result(" ");
    for (auto column: columns) {
        result += column + ",";
    }                       
    result[result.size() - 1] = ' '; // 一个好的将数组转化为逗号分割字符串的思路，将最后一个逗号替换为空白
    return result;
}

/*
 \N是NULL的替代符号

 生成符号分割字符串的好思路 again！
*/
std::string 
tab_separated(const std::vector<std::string> &columns) {
    std::string result(" ");
    for (auto column: columns) {
        if (column.empty() || column == "") {
            result += "\\N\t";
        } else {
            result += column + "\t";
        }
    }                       
    result[result.size() - 1] = '\n'; 
    return result;
}
