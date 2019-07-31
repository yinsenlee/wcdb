/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/WINQ.h>

namespace WCDB {

OrderingTerm::OrderingTerm(const Expression& expression)
{
    syntax().expression = expression;
}

OrderingTerm& OrderingTerm::collate(const UnsafeStringView& collation)
{
    syntax().collation = collation;
    return *this;
}

OrderingTerm& OrderingTerm::order(const Order& order)
{
    syntax().order = order;
    return *this;
}

const OrderingTerm& OrderingTerm::ascendingRowid()
{
    WCDB_STATIC_VARIABLE const OrderingTerm s_ascendingRowid(
    OrderingTerm(Column::rowid()).order(WCDB::Order::ASC));
    return s_ascendingRowid;
}

} // namespace WCDB
