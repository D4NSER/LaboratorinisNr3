#include "CppUnitTest.h"
#include "vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace v30TEST
{
    TEST_CLASS(VectorTests)
    {
    public:

        TEST_METHOD(InitiallyEmpty)
        {
            Vector<int> vec;
            Assert::IsTrue(vec.empty());
            Assert::AreEqual(vec.size(), static_cast<size_t>(0));
        }

        TEST_METHOD(PushBack)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            Assert::AreEqual(vec.size(), static_cast<size_t>(2));
            Assert::AreEqual(vec[0], 1);
            Assert::AreEqual(vec[1], 2);
        }

        TEST_METHOD(PopBack)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.pop_back();
            Assert::AreEqual(vec.size(), static_cast<size_t>(1));
            Assert::AreEqual(vec[0], 1);
        }

        TEST_METHOD(Clear)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.clear();
            Assert::IsTrue(vec.empty());
            Assert::AreEqual(vec.size(), static_cast<size_t>(0));
        }

        TEST_METHOD(Capacity)
        {
            Vector<int> vec;
            Assert::AreEqual(vec.capacity(), static_cast<size_t>(0));
            vec.push_back(1);
            Assert::AreEqual(vec.capacity(), static_cast<size_t>(1));
            vec.push_back(2);
            Assert::AreEqual(vec.capacity(), static_cast<size_t>(2));
        }

        TEST_METHOD(Iterators)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);

            int expected = 1;
            for (auto it = vec.begin(); it != vec.end(); ++it)
            {
                Assert::AreEqual(*it, expected++);
            }
        }

        TEST_METHOD(Sort)
        {
            Vector<int> vec;
            vec.push_back(3);
            vec.push_back(1);
            vec.push_back(2);

            vec.sort();

            Assert::AreEqual(vec[0], 1);
            Assert::AreEqual(vec[1], 2);
            Assert::AreEqual(vec[2], 3);
        }

        TEST_METHOD(Reverse)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);

            vec.reverse();

            Assert::AreEqual(vec[0], 3);
            Assert::AreEqual(vec[1], 2);
            Assert::AreEqual(vec[2], 1);
        }

        TEST_METHOD(AccessByIndex)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);

            Assert::AreEqual(vec[0], 1);
            Assert::AreEqual(vec[1], 2);
        }

        TEST_METHOD(AccessByIndexOutOfRange)
        {
            Vector<int> vec;
            vec.push_back(1);

            Assert::ExpectException<std::out_of_range>([&] { int x = vec[1]; });
        }

        TEST_METHOD(CopyConstructor)
        {
            Vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);

            Vector<int> vec2(vec1);

            Assert::AreEqual(vec1.size(), vec2.size());
            for (size_t i = 0; i < vec1.size(); ++i)
            {
                Assert::AreEqual(vec1[i], vec2[i]);
            }
        }

        TEST_METHOD(CopyAssignmentOperator)
        {
            Vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);

            Vector<int> vec2;
            vec2 = vec1;

            Assert::AreEqual(vec1.size(), vec2.size());
            for (size_t i = 0; i < vec1.size(); ++i)
            {
                Assert::AreEqual(vec1[i], vec2[i]);
            }
        }

        TEST_METHOD(MoveConstructor)
        {
            Vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);

            Vector<int> vec2(std::move(vec1));

            Assert::AreEqual(vec2.size(), static_cast<size_t>(2));
            Assert::AreEqual(vec2[0], 1);
            Assert::AreEqual(vec2[1], 2);
            Assert::IsTrue(vec1.empty());
        }

        TEST_METHOD(MoveAssignmentOperator)
        {
            Vector<int> vec1;
            vec1.push_back(1);
            vec1.push_back(2);

            Vector<int> vec2;
            vec2 = std::move(vec1);

            Assert::AreEqual(vec2.size(), static_cast<size_t>(2));
            Assert::AreEqual(vec2[0], 1);
            Assert::AreEqual(vec2[1], 2);
            Assert::IsTrue(vec1.empty());
        }

        // New tests:

        TEST_METHOD(Insert)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(3);

            vec.insert(vec.begin() + 1, 2);

            Assert::AreEqual(vec[0], 1);
            Assert::AreEqual(vec[1], 2);
            Assert::AreEqual(vec[2], 3);
        }

        TEST_METHOD(Erase)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);

            vec.erase(vec.begin() + 1);

            Assert::AreEqual(vec[0], 1);
            Assert::AreEqual(vec[1], 3);
            Assert::AreEqual(vec.size(), static_cast<size_t>(2));
        }

        TEST_METHOD(IsSorted)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);

            Assert::IsTrue(vec.is_sorted());

            vec.push_back(1);

            Assert::IsFalse(vec.is_sorted());
        }

        TEST_METHOD(AccessInvalidIndex)
        {
            Vector<int> vec;
            // Try accessing elements using invalid indices
            Assert::ExpectException<std::out_of_range>([&] { int x = vec[0]; });
            vec.push_back(10);
            Assert::ExpectException<std::out_of_range>([&] { int x = vec[1]; });
        }

        TEST_METHOD(SortPerformance)
        {
            // Test the performance of sorting a large vector
            const int size = 10000; // Adjust the size as needed
            Vector<int> vec;
            // Fill the vector with random elements
            for (int i = 0; i < size; ++i)
            {
                vec.push_back(rand());
            }
            auto startTime = std::chrono::high_resolution_clock::now();
            vec.sort();
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
            Logger::WriteMessage(("Sorting time for " + std::to_string(size) + " elements: " + std::to_string(duration) + " milliseconds").c_str());
            // Check if the vector is sorted
            for (size_t i = 1; i < vec.size(); ++i)
            {
                Assert::IsTrue(vec[i - 1] <= vec[i]);
            }
        }

        TEST_METHOD(InsertAtDifferentPositions)
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(3);
            vec.push_back(5);

            // Insert at the beginning
            vec.insert(vec.begin(), 0);
            Assert::AreEqual(vec[0], 0);
            Assert::AreEqual(vec[1], 1);
            Assert::AreEqual(vec[2], 3);
            Assert::AreEqual(vec[3], 5);

            // Insert at the middle
            vec.insert(vec.begin() + 2, 2);
            Assert::AreEqual(vec[0], 0);
            Assert::AreEqual(vec[1], 1);
            Assert::AreEqual(vec[2], 2);
            Assert::AreEqual(vec[3], 3);
            Assert::AreEqual(vec[4], 5);

            // Insert at the end
            vec.insert(vec.end(), 6);
            Assert::AreEqual(vec[0], 0);
            Assert::AreEqual(vec[1], 1);
            Assert::AreEqual(vec[2], 2);
            Assert::AreEqual(vec[3], 3);
            Assert::AreEqual(vec[4], 5);
            Assert::AreEqual(vec[5], 6);
        }

    };
}
