using System;
using System.Runtime;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using Plang.CSharpRuntime;
using Plang.CSharpRuntime.Values;
using Plang.CSharpRuntime.Exceptions;
using System.Threading;
using System.Threading.Tasks;

#pragma warning disable 162, 219, 414
namespace PImplementation
{
    public static partial class GlobalFunctions
    {
        public static bool sleepFor(int sleeptime, PMachine pMachine)
        {
            System.Threading.Thread.Sleep(sleeptime);
            return true;
        }
    }
}